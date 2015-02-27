{ 
	'targets': [
    {
        'target_name': 'str2argv',
        'type': 'static_library',
		'includes':[
			'./config.gypi',
		],
		'sources': [
            "str2argv/str2argv.h",
            "str2argv/str2argv.c",
		],
    },
	]
}
