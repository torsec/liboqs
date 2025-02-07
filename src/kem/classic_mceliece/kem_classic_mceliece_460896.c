// SPDX-License-Identifier: MIT

#include <stdlib.h>

#include <oqs/kem_classic_mceliece.h>

#if defined(OQS_ENABLE_KEM_classic_mceliece_460896)

OQS_KEM *OQS_KEM_classic_mceliece_460896_new(void) {

	OQS_KEM *kem = OQS_MEM_malloc(sizeof(OQS_KEM));
	if (kem == NULL) {
		return NULL;
	}
	kem->method_name = OQS_KEM_alg_classic_mceliece_460896;
	kem->alg_version = "SUPERCOP-20221025";

	kem->claimed_nist_level = 3;
	kem->ind_cca = true;

	kem->length_public_key = OQS_KEM_classic_mceliece_460896_length_public_key;
	kem->length_secret_key = OQS_KEM_classic_mceliece_460896_length_secret_key;
	kem->length_ciphertext = OQS_KEM_classic_mceliece_460896_length_ciphertext;
	kem->length_shared_secret = OQS_KEM_classic_mceliece_460896_length_shared_secret;
	kem->length_keypair_coins = OQS_KEM_classic_mceliece_460896_length_keypair_coins;
	kem->length_encaps_coins = OQS_KEM_classic_mceliece_460896_length_encaps_coins;

	kem->keypair_derand = OQS_KEM_classic_mceliece_460896_keypair_derand;
	kem->keypair = OQS_KEM_classic_mceliece_460896_keypair;
	kem->encaps_derand = OQS_KEM_classic_mceliece_460896_encaps_derand;
	kem->encaps = OQS_KEM_classic_mceliece_460896_encaps;
	kem->decaps = OQS_KEM_classic_mceliece_460896_decaps;

	return kem;
}

extern int PQCLEAN_MCELIECE460896_CLEAN_crypto_kem_keypair(uint8_t *pk, uint8_t *sk);
extern int PQCLEAN_MCELIECE460896_CLEAN_crypto_kem_enc(uint8_t *ct, uint8_t *ss, const uint8_t *pk);
extern int PQCLEAN_MCELIECE460896_CLEAN_crypto_kem_dec(uint8_t *ss, const uint8_t *ct, const uint8_t *sk);

#if defined(OQS_ENABLE_KEM_classic_mceliece_460896_avx2)
extern int PQCLEAN_MCELIECE460896_AVX2_crypto_kem_keypair(uint8_t *pk, uint8_t *sk);
extern int PQCLEAN_MCELIECE460896_AVX2_crypto_kem_enc(uint8_t *ct, uint8_t *ss, const uint8_t *pk);
extern int PQCLEAN_MCELIECE460896_AVX2_crypto_kem_dec(uint8_t *ss, const uint8_t *ct, const uint8_t *sk);
#endif

OQS_API OQS_STATUS OQS_KEM_classic_mceliece_460896_keypair_derand(uint8_t *public_key, uint8_t *secret_key, const uint8_t *coins) {
	(void)public_key;
	(void)secret_key;
	(void)coins;
	return OQS_ERROR;
}

OQS_API OQS_STATUS OQS_KEM_classic_mceliece_460896_keypair(uint8_t *public_key, uint8_t *secret_key) {
#if defined(OQS_ENABLE_KEM_classic_mceliece_460896_avx2)
#if defined(OQS_DIST_BUILD)
	if (OQS_CPU_has_extension(OQS_CPU_EXT_AVX2) && OQS_CPU_has_extension(OQS_CPU_EXT_POPCNT)) {
#endif /* OQS_DIST_BUILD */
		return (OQS_STATUS) PQCLEAN_MCELIECE460896_AVX2_crypto_kem_keypair(public_key, secret_key);
#if defined(OQS_DIST_BUILD)
	} else {
		return (OQS_STATUS) PQCLEAN_MCELIECE460896_CLEAN_crypto_kem_keypair(public_key, secret_key);
	}
#endif /* OQS_DIST_BUILD */
#else
	return (OQS_STATUS) PQCLEAN_MCELIECE460896_CLEAN_crypto_kem_keypair(public_key, secret_key);
#endif
}

OQS_API OQS_STATUS OQS_KEM_classic_mceliece_460896_encaps_derand(uint8_t *ciphertext, uint8_t *shared_secret, const uint8_t *public_key, const uint8_t *coins) {
	(void)ciphertext;
	(void)shared_secret;
	(void)public_key;
	(void)coins;
	return OQS_ERROR;
}

OQS_API OQS_STATUS OQS_KEM_classic_mceliece_460896_encaps(uint8_t *ciphertext, uint8_t *shared_secret, const uint8_t *public_key) {
#if defined(OQS_ENABLE_KEM_classic_mceliece_460896_avx2)
#if defined(OQS_DIST_BUILD)
	if (OQS_CPU_has_extension(OQS_CPU_EXT_AVX2) && OQS_CPU_has_extension(OQS_CPU_EXT_POPCNT)) {
#endif /* OQS_DIST_BUILD */
		return (OQS_STATUS) PQCLEAN_MCELIECE460896_AVX2_crypto_kem_enc(ciphertext, shared_secret, public_key);
#if defined(OQS_DIST_BUILD)
	} else {
		return (OQS_STATUS) PQCLEAN_MCELIECE460896_CLEAN_crypto_kem_enc(ciphertext, shared_secret, public_key);
	}
#endif /* OQS_DIST_BUILD */
#else
	return (OQS_STATUS) PQCLEAN_MCELIECE460896_CLEAN_crypto_kem_enc(ciphertext, shared_secret, public_key);
#endif
}

OQS_API OQS_STATUS OQS_KEM_classic_mceliece_460896_decaps(uint8_t *shared_secret, const uint8_t *ciphertext, const uint8_t *secret_key) {
#if defined(OQS_ENABLE_KEM_classic_mceliece_460896_avx2)
#if defined(OQS_DIST_BUILD)
	if (OQS_CPU_has_extension(OQS_CPU_EXT_AVX2) && OQS_CPU_has_extension(OQS_CPU_EXT_POPCNT)) {
#endif /* OQS_DIST_BUILD */
		return (OQS_STATUS) PQCLEAN_MCELIECE460896_AVX2_crypto_kem_dec(shared_secret, ciphertext, secret_key);
#if defined(OQS_DIST_BUILD)
	} else {
		return (OQS_STATUS) PQCLEAN_MCELIECE460896_CLEAN_crypto_kem_dec(shared_secret, ciphertext, secret_key);
	}
#endif /* OQS_DIST_BUILD */
#else
	return (OQS_STATUS) PQCLEAN_MCELIECE460896_CLEAN_crypto_kem_dec(shared_secret, ciphertext, secret_key);
#endif
}

#endif
