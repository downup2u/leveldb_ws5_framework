{

	'targets': [
	{  
		'target_name': "wscli",
		'type':'executable',	
		 'includes':[
			'../deps/osconfig.gypi',
			'../proj/configd.gypi',
		],
		'dependencies': [
			'../deps/protobuf3.gyp:protobuf_full_do_not_use',
			'../deps/json2pb.gyp:json2pb',
			'../deps/jansson.gyp:jansson',		
			'../deps/glog.gyp:glog',
			'../deps/leveldb.gyp:leveldb',
		],
		'include_dirs': [
			'../deps/boost_1_57_0',
			'../deps/websocketpp-master',
			'../deps/protobuf3/src',
			'../deps/json2pb-master',
			'../deps/glog/src',
			'../deps/leveldb/include',
			'../src/proto',
			'../src/proto/model',
			'../src/util',

			],
		'sources': [ 
			'../src/leveldbwscli/wscli.cc',
			'../src/leveldbwscli/wscli.h',
			'../src/leveldbwscli/wsclimain.cc',
			'../src/leveldbwscli/wsclimain.h',
			'../src/leveldbwscli/main.cc',
			'../src/util/codec.cc',
			'../src/util/codec.h',
			'../src/util/codecinmsg.cc',
			'../src/util/codecinmsg.h',
			'../src/util/glog.cc',
			'../src/util/glog.h',
			'../src/util/nodeexception.h',
			'../src/proto/packmsg.pb.cc',
			'../src/proto/packmsg.pb.h',
			'../src/proto/model/model_db.pb.cc',
			'../src/proto/model/model_db.pb.h',
			'../src/proto/model/model_comm.pb.cc',
			'../src/proto/model/model_comm.pb.h',
		],
		'conditions': [
			['OS=="win"', {
				'libraries': [
					'Advapi32.lib',
					'User32.lib'
				],
			}]
		],
    }],
}	