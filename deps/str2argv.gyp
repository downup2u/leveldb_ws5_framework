{ 
	'targets': [
    {
        'target_name': 'str2argv',
        'type': 'static_library',
		'includes':[
			'./config.gypi',
		],
		'sources': [
            "cstr2argv/str2argv.h",
            "cstr2argv/str2argv.c",
		],
    },
	]
}
