/************
 *
 * Filename:  bsuproto.h
 *
 * Purpose:   user prototypes for bs
 *
 * Copyright: (c) 2016 WOORINET. All rights reserved.
 *
 ************/

#ifdef __cplusplus
extern "C"{
#endif

/* bsuser */
extern void    bs_init(void);
extern void    bs_post_init(void);
extern boolean bs_customer_get(char *strp);
extern boolean bs_current_customer(const char *strp);
extern boolean bs_fotaconf_get(uint32 *fota_conf);
extern boolean bs_fotaconf_set(uint32 fota_conf);
extern boolean bs_fotamode_get(uint32 *fota_mode);
extern boolean bs_fotamode_set(uint32 fota_mode);
extern boolean bs_feature_get(enum bsfeature feature);
extern boolean bs_project_name_get(char *strp);
extern boolean bs_current_carrier(const char *strp);
extern boolean bs_carrier_get(char *strp);
extern boolean TARGET_SKT(void);
extern boolean TARGET_KT(void);
extern boolean TARGET_LGU(void);
extern int is_skt(void);
extern int is_kt(void);
extern int is_lgu(void);
extern boolean bs_mcfg_carrier_get(char *strp);
extern boolean bs_current_mcfg_carrier(const char *strp);
extern int32 bs_systemtext(char   *cmdp,
                           size_t  maxtext,
                           char   *strp,
                           size_t *lenp);

#ifdef __cplusplus
}
#endif

