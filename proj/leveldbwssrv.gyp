{
	'targets': [
	{    
		'target_name': "wssrv",
		'type':'executable',
		'defines': [
			'LCBUV_EMBEDDED_SOURCE=1',
		 ],	
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
			'<(jansson_config_h_dir)',
			'../deps/json2pb-master',
			'../deps/glog/src',
			'../deps/leveldb/include',
			'../deps/encryptstring',
			'../deps/include',
			'../src/proto',
			'../src/proto/custommsg',
			'../src/util',
			'../src/leveldbwssrv/couchbase',
		],
		'sources': [ 
			'../src/leveldbwssrv/wssrv.cc',
			'../src/leveldbwssrv/wssrv.h',
			'../src/leveldbwssrv/wssrvmain.cc',
			'../src/leveldbwssrv/wssrvmain.h',
			'../src/leveldbwssrv/sessconn.h',
			'../src/leveldbwssrv/sessconn.cc',
			'../src/leveldbwssrv/sessdbdispatcher.h',
			'../src/leveldbwssrv/sessdbdispatcher.cc',
			'../src/leveldbwssrv/dispatcher.hpp',
			'../src/leveldbwssrv/main.cc',
			'../src/util/codec.cc',
			'../src/util/codec.h',
			'../src/util/codecinmsg.cc',
			'../src/util/codecinmsg.h',
			'../src/util/glog.cc',
			'../src/util/glog.h',
			'../src/util/nodeexception.h',
			'../src/proto/packmsg.pb.cc',
			'../src/proto/packmsg.pb.h',
			'../src/proto/custommsg/xkcrm.pb.cc',
			'../src/proto/custommsg/xkcrm.pb.h',
			'../src/proto/custommsg/nosqldb.pb.cc',
			'../src/proto/custommsg/nosqldb.pb.h',
		],
		'conditions': [
			['OS=="win"', {
				'libraries': [
					'Advapi32.lib',
					'User32.lib',
				],
			}]
		],
    }],
}