/*************
 *
 * Filename:  aauproto.h
 *
 * Purpose:   user prototypes for aa
 *
 * Copyright: (c) 2016 WOORINET. All rights reserved.
 *
 **************/

/* Prototypes */
extern const char *aa_build_tag_get(
  const char * carrier);
extern const char *aa_build_ofc_tag_get(
  const char * carrier);
extern const char *aa_git_revision_get(
  void);
extern const char *aa_git_qti_apps_version_get(
  void);
extern const char *aa_git_qti_version_get(
  void);
extern const char *aa_git_commit_id_get(
  void);
extern const char *aa_build_machine_get(
  void);
extern const char *aa_build_date_time_get(
  void);
extern const char *aa_build_date_get(
  void);
extern const char *aa_build_time_get(
  void);
extern const char *aa_version_tag_get(
  const char * carrier);
extern const char *aa_fake_ver_date_time_get(
  void);

