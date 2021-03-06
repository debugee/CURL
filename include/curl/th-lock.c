#include "curl\curl.h"
#include <Windows.h>
#include <openssl/crypto.h>


static HANDLE *lock_cs;


CURL_EXTERN void win32_locking_callback(int mode, int type, const char *file, int line)
{
	type;
	file;
	line;
	if (mode & CRYPTO_LOCK) {
		WaitForSingleObject(lock_cs[type], INFINITE);
	}
	else {
		ReleaseMutex(lock_cs[type]);
	}
}

CURL_EXTERN void CRYPTO_thread_setup(void)
{
	int i;

	lock_cs = OPENSSL_malloc(CRYPTO_num_locks() * sizeof(HANDLE));
	if (!lock_cs) {
		/* Nothing we can do about this...void function! */
		return;
	}
	for (i = 0; i < CRYPTO_num_locks(); i++) {
		lock_cs[i] = CreateMutex(NULL, FALSE, NULL);
	}

	CRYPTO_set_locking_callback(&win32_locking_callback);
	/* id callback defined */
	return;
}

void CRYPTO_thread_cleanup(void)
{
	int i;

	CRYPTO_set_locking_callback(NULL);
	for (i = 0; i < CRYPTO_num_locks(); i++)
		CloseHandle(lock_cs[i]);
	OPENSSL_free(lock_cs);
}

