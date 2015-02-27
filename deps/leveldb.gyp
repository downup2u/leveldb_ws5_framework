# Copyright (c) 2011 The LevelDB Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file. See the AUTHORS file for names of contributors.

{
  'variables': {
    'use_snappy%': 1,
	'leveldb_dir':'leveldb'
  },
  'target_defaults': {
    'include_dirs': [
      '<(leveldb_dir)',
      '<(leveldb_dir)/include/',
      'snappy',
    ],
	'includes':[
		'osconfig.gypi',
	 ],

    'conditions': [
      ['OS == "win"', {
        'include_dirs': [
          '<(leveldb_dir)/port/win',		  
        ],
	   'defines': [		 
			'LEVELDB_PLATFORM_WINDOWS=1',
			'OS_WIN=1'
        ],

      }],
	  [ 'OS=="linux"', {
	   'defines': [		 
			'LEVELDB_PLATFORM_POSIX=1',
        ]
      }],
      ['OS == "mac"', {
        'defines': [		 
          'OS_MACOSX=1',
          'PLATFORM=OS_MACOSX',
		  'LEVELDB_PLATFORM_POSIX=1',
        ]
      }],
      ['OS == "solaris"', {
        'defines': [
          'OS_SOLARIS',
          '_REENTRANT',
          
        ]
      }],
      ['use_snappy', {
        'defines': [
          'SNAPPY=1',
        ],
      }],
    ],
  },
  'targets': [
    {
      'target_name': 'leveldb',
      'type': 'static_library',
      'conditions': [
        ['use_snappy', {
          'dependencies': [
            'snappy.gyp:snappy',
          ],
        }],
      ],
     'conditions': [
          ['OS == "win"', {
            'include_dirs': [
              '<(leveldb_dir)/port/win',
            ],
			'sources': [
			'<(leveldb_dir)/port/port_win.cc',
			'<(leveldb_dir)/util/env_win.cc',
			'<(leveldb_dir)/util/env_win_detail/win_misc.cc',
			'<(leveldb_dir)/util/env_win_detail/win_mmap.cc',
			'<(leveldb_dir)/util/env_win_detail/win_thread.cc',
			'<(leveldb_dir)/util/env_win_detail/win_time.cc',
			'<(leveldb_dir)/util/env_win_detail/winapi.cc',
			],
			'libraries': [
					'Advapi32.lib',		
				],
          }],
        
		 [ 'OS=="linux"', {
			'sources': [		 
			'<(leveldb_dir)/port/port_posix.cc',
			'<(leveldb_dir)/util/env_posix.cc',
        ]}],
	  ],
      'sources': [
        # Include and then exclude so that all files show up in IDEs, even if
        # they don't build.
        '<(leveldb_dir)/db/builder.cc',
        '<(leveldb_dir)/db/builder.h',
        '<(leveldb_dir)/db/db_impl.cc',
        '<(leveldb_dir)/db/db_impl.h',
        '<(leveldb_dir)/db/db_iter.cc',
        '<(leveldb_dir)/db/db_iter.h',
        '<(leveldb_dir)/db/filename.cc',
        '<(leveldb_dir)/db/filename.h',
        '<(leveldb_dir)/db/dbformat.cc',
        '<(leveldb_dir)/db/dbformat.h',
        '<(leveldb_dir)/db/log_format.h',
        '<(leveldb_dir)/db/log_reader.cc',
        '<(leveldb_dir)/db/log_reader.h',
        '<(leveldb_dir)/db/log_writer.cc',
        '<(leveldb_dir)/db/log_writer.h',
        '<(leveldb_dir)/db/memtable.cc',
        '<(leveldb_dir)/db/memtable.h',
        '<(leveldb_dir)/db/repair.cc',
        '<(leveldb_dir)/db/skiplist.h',
        '<(leveldb_dir)/db/snapshot.h',
        '<(leveldb_dir)/db/table_cache.cc',
        '<(leveldb_dir)/db/table_cache.h',
        '<(leveldb_dir)/db/version_edit.cc',
        '<(leveldb_dir)/db/version_edit.h',
        '<(leveldb_dir)/db/version_set.cc',
        '<(leveldb_dir)/db/version_set.h',
        '<(leveldb_dir)/db/write_batch.cc',
        '<(leveldb_dir)/db/write_batch_internal.h',
        '<(leveldb_dir)/include/leveldb/cache.h',
        '<(leveldb_dir)/include/leveldb/comparator.h',
        '<(leveldb_dir)/include/leveldb/db.h',
        '<(leveldb_dir)/include/leveldb/env.h',
        '<(leveldb_dir)/include/leveldb/filter_policy.h',
        '<(leveldb_dir)/include/leveldb/iterator.h',
        '<(leveldb_dir)/include/leveldb/options.h',
        '<(leveldb_dir)/include/leveldb/slice.h',
        '<(leveldb_dir)/include/leveldb/status.h',
        '<(leveldb_dir)/include/leveldb/table.h',
        '<(leveldb_dir)/include/leveldb/table_builder.h',
        '<(leveldb_dir)/include/leveldb/write_batch.h',
        '<(leveldb_dir)/port/port.h',
        '<(leveldb_dir)/port/port_example.h',
        '<(leveldb_dir)/table/block.cc',
        '<(leveldb_dir)/table/block.h',
        '<(leveldb_dir)/table/filter_block.cc',
        '<(leveldb_dir)/table/filter_block.h',
        '<(leveldb_dir)/table/block_builder.cc',
        '<(leveldb_dir)/table/block_builder.h',
        '<(leveldb_dir)/table/format.cc',
        '<(leveldb_dir)/table/format.h',
        '<(leveldb_dir)/table/iterator.cc',
        '<(leveldb_dir)/table/iterator_wrapper.h',
        '<(leveldb_dir)/table/merger.cc',
        '<(leveldb_dir)/table/merger.h',
        '<(leveldb_dir)/table/table.cc',
        '<(leveldb_dir)/table/table_builder.cc',
        '<(leveldb_dir)/table/two_level_iterator.cc',
        '<(leveldb_dir)/table/two_level_iterator.h',
        '<(leveldb_dir)/util/arena.cc',
        '<(leveldb_dir)/util/arena.h',
        '<(leveldb_dir)/util/bloom.cc',
        '<(leveldb_dir)/util/cache.cc',
        '<(leveldb_dir)/util/coding.cc',
        '<(leveldb_dir)/util/coding.h',
        '<(leveldb_dir)/util/comparator.cc',
        '<(leveldb_dir)/util/crc32c.cc',
        '<(leveldb_dir)/util/crc32c.h',
        '<(leveldb_dir)/util/env.cc',
        '<(leveldb_dir)/util/filter_policy.cc',
        '<(leveldb_dir)/util/hash.cc',
        '<(leveldb_dir)/util/hash.h',
        '<(leveldb_dir)/util/logging.cc',
        '<(leveldb_dir)/util/logging.h',
        '<(leveldb_dir)/util/mutexlock.h',
        '<(leveldb_dir)/util/options.cc',
        '<(leveldb_dir)/util/random.h',
        '<(leveldb_dir)/util/status.cc',
      ],
      'sources/': [
        ['exclude', '_(android|example|portable)\\.cc$'],
      ],
    },
    {
      'target_name': 'leveldb_testutil',
      'type': 'static_library',
      'dependencies': [
        'leveldb',
      ],
      'export_dependent_settings': [
        # The tests use include directories from these projects.
        'leveldb',
      ],
      'sources': [
        '<(leveldb_dir)/util/histogram.cc',
        '<(leveldb_dir)/util/histogram.h',
        '<(leveldb_dir)/util/testharness.cc',
        '<(leveldb_dir)/util/testharness.h',
        '<(leveldb_dir)/util/testutil.cc',
        '<(leveldb_dir)/util/testutil.h',
      ],
    },
    {
      'target_name': 'leveldb_arena_test',
      'type': 'executable',
      'dependencies': [
        'leveldb_testutil',
      ],
      'sources': [
        '<(leveldb_dir)/util/arena_test.cc',
      ],
    },
    {
      'target_name': 'leveldb_bloom_test',
      'type': 'executable',
      'dependencies': [
        'leveldb_testutil',
      ],
      'sources': [
        '<(leveldb_dir)/util/bloom_test.cc',
      ],
    },
    {
      'target_name': 'leveldb_cache_test',
      'type': 'executable',
      'dependencies': [
        'leveldb_testutil',
      ],
      'sources': [
        '<(leveldb_dir)/util/cache_test.cc',
      ],
    },
    {
      'target_name': 'leveldb_coding_test',
      'type': 'executable',
      'dependencies': [
        'leveldb_testutil',
      ],
      'sources': [
        '<(leveldb_dir)/util/coding_test.cc',
      ],
    },
    {
      'target_name': 'leveldb_corruption_test',
      'type': 'executable',
      'dependencies': [
        'leveldb_testutil',
      ],
      'sources': [
        '<(leveldb_dir)/db/corruption_test.cc',
      ],
    },
    {
      'target_name': 'leveldb_crc32c_test',
      'type': 'executable',
      'dependencies': [
        'leveldb_testutil',
      ],
      'sources': [
        '<(leveldb_dir)/util/crc32c_test.cc',
      ],
    },
    {
      'target_name': 'leveldb_db_bench',
      'type': 'executable',
      'dependencies': [
        'leveldb_testutil',
      ],
      'sources': [
        '<(leveldb_dir)/db/db_bench.cc',
      ],
    },
    {
      'target_name': 'leveldb_db_test',
      'type': 'executable',
      'dependencies': [
        'leveldb_testutil',
      ],
      'sources': [
        '<(leveldb_dir)/db/db_test.cc',
      ],
    },
    {
      'target_name': 'leveldb_dbformat_test',
      'type': 'executable',
      'dependencies': [
        'leveldb_testutil',
      ],
      'sources': [
        '<(leveldb_dir)/db/dbformat_test.cc',
      ],
    },
    {
      'target_name': 'leveldb_env_test',
      'type': 'executable',
      'dependencies': [
        'leveldb_testutil',
      ],
      'sources': [
        '<(leveldb_dir)/util/env_test.cc',
      ],
    },
    {
      'target_name': 'leveldb_filename_test',
      'type': 'executable',
      'dependencies': [
        'leveldb_testutil',
      ],
      'sources': [
        '<(leveldb_dir)/db/filename_test.cc',
      ],
    },
    {
      'target_name': 'leveldb_log_test',
      'type': 'executable',
      'dependencies': [
        'leveldb_testutil',
      ],
      'sources': [
        '<(leveldb_dir)/db/log_test.cc',
      ],
    },
    {
      'target_name': 'leveldb_skiplist_test',
      'type': 'executable',
      'dependencies': [
        'leveldb_testutil',
      ],
      'sources': [
        '<(leveldb_dir)/db/skiplist_test.cc',
      ],
    },
    {
      'target_name': 'leveldb_table_test',
      'type': 'executable',
      'dependencies': [
        'leveldb_testutil',
      ],
      'sources': [
        '<(leveldb_dir)/table/table_test.cc',
      ],
    },
    {
      'target_name': 'leveldb_version_edit_test',
      'type': 'executable',
      'dependencies': [
        'leveldb_testutil',
      ],
      'sources': [
        '<(leveldb_dir)/db/version_edit_test.cc',
      ],
    },
    {
      'target_name': 'leveldb_write_batch_test',
      'type': 'executable',
      'dependencies': [
        'leveldb_testutil',
      ],
      'sources': [
        '<(leveldb_dir)/db/write_batch_test.cc',
      ],
    },
  ],
}

# Local Variables:
# tab-width:2
# indent-tabs-mode:nil
# End:
# vim: set expandtab tabstop=2 shiftwidth=2:
