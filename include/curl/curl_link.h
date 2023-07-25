#pragma once


#ifdef _DEBUG
	#ifdef _DLL
		#if _MSC_VER == 1800
			#pragma comment(lib, "v12_smdd_libcurl.lib")
		#elif _MSC_VER == 1900
			#pragma comment(lib, "v14_smdd_libcurl.lib")
		#endif
	#else
		#if _MSC_VER == 1800
			#pragma comment(lib, "v12_smtd_libcurl.lib")
		#elif _MSC_VER == 1900
			#pragma comment(lib, "v14_smtd_libcurl.lib")
		#endif
	#endif
#else
	#ifdef _DLL
		#if _MSC_VER == 1800
			#pragma comment(lib, "v12_smd_libcurl.lib")
		#elif _MSC_VER == 1900
			#pragma comment(lib, "v14_smd_libcurl.lib")
		#endif
	#else
		#if _MSC_VER == 1800
			#pragma comment(lib, "v12_smt_libcurl.lib")
		#elif _MSC_VER == 1900
			#pragma comment(lib, "v14_smt_libcurl.lib")
		#endif
	#endif
#endif
