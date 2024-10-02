/*************
 *
 * Filename:  sluproto - user prototypes for sl
 *
 * Copyright: (c) 2020 WOORINET. All rights reserved.
 *
 **************/

/* missing prototype */
extern int vsscanf( const char *str, const char *format, va_list argp);

/* Prototypes */
extern uint64 slahtouint64(const char *sp);
extern uint32 slahtol(const char *sp);
extern uint16 slatoi(const char *sp);
extern uint32 slatol(const char *sp);
extern void sldelstrinstr(char *s1, const char *delstr2);
extern int slstrcmpcaseinsensitive(const char *s1p, const char *s2p);
extern char sltoupper(char c);
extern boolean slisprint(char c);
extern char *slstrtok(char *strtokp, const char *strdelimitp, struct slstrtokblk *strtokblkp);
extern boolean slasciihextouint8(char *srcp, uint8 *value);
extern char *sluint8toasciihex(char *destp, uint8 value);
extern char *sluint16toasciihex(char *destp, uint16 value);
extern char *sluint32toasciihex(char *destp, uint32 value);
extern char *sluint8toasciidec(char *destp, uint8 value);
extern uint32 slvsprintflen(char *bufp,
                            const char *fmtp,
                            va_list argp,
                            uint32 maxlen);
extern char *slsprintf (char *bufp, const char *fmtp, ...);
extern char *slint16toasciidec(char *destp, int16 value);
extern char *sluint16toasciidec(char *destp, uint16 value);
extern boolean slisdigit(char digit);
extern boolean slisdigitstring(const char *inputp);
extern boolean slishex(char hex);
extern boolean slishexstring(const char *inputp);
extern boolean slisletter(char c);
extern uint64 slatouint64(const char *sp);
extern boolean slbin2hexstr( uint32 len, uint8 *datap,uint32 slen, char *strp );
extern uint32 slhexstr2bin( uint32 slen, char *strp, uint32 len, uint8 *datap );
extern char * slbasename(const char * path);
extern char * sldirname(char * path);

extern uint8 slahtouint8(char *sp);
extern uint16 slahtouint16(char *sp);
extern char sltolower(char c);
extern boolean slisstrinstr(const char *s1, uint16 len1, const char *s2, uint16 len2);
extern char *slsearchstrinstr(const char *s1, uint32 len1, const char *s2, uint32 len2);
extern char *sluint32toasciidec(char *destp, uint32 input);
extern char *sluint64toasciidec(char *destp, uint64 input);
extern char *sluint64toasciihex(char *destp, uint64 value);
extern boolean slatosl(const char *sp, int32 *outp);
extern boolean slisalphanum(char c);
extern uint16 slascii2ucs(uint8 *dststringp, uint16 maxchars, uint8 *srcstringp, uint16 numchars);
extern uint16 slascii2ucs_host(uint8 *dststringp, uint16 maxchars, uint8 *srcstringp, uint16 numchars);
extern uint16 slucs2ascii(uint8 *dststringp, uint16 maxchars, uint8 *srcstringp, uint16 numchars);
extern boolean slipstrtouint32( uint32 *ipuint32p, char *ipstringp, uint8 maxstrsize);
extern char *slint16tofloatpt(char *destp, int16 input);
extern boolean slfloattoint16(int16 *return_val, char *sp);
extern void slstrerase(char * destp, const char* srcp, uint8 idx, uint8 len);
extern void slstrinsert(char * destp, const char* srcp, const char* substrp, uint8 idx, uint8 len);
extern boolean slcatosl(const char *sp, int32 *outp);


extern uint32 slsscanf(char *instrp, const char *formatp, ...);

extern void sljultimetoutc( char *srcp, uint32 * timestamp_utc_p);

extern void slutctojulstruct( struct time_julian_type *destp, uint32 utc);
extern char *slutctojultime( char *destp, uint32 timestamp_utc);
extern int32 slUtf8ToUcs2( unsigned char *utf8stringp,
                           UCS2      *usc2stringp,
                           uint16    maxnumchars,
                           uint16    *numcharsp );

extern int32 slUcs2ToUtf8( UCS2      *ucs2stringp,
                           uint16    numucs2chars,
                           unsigned char *utf8stringp,
                           uint16    maxbytes );
extern int sl_dec_suffix_to_int(const char *path);

extern void slstrerase(
  char * destp,
  const char* srcp,
  uint8 idx,
  uint8 len);

extern void slstrinsert(
  char * destp,
  const char* srcp,
  const char* substrp,
  uint8 idx,
  uint8 len);

extern uint32 slstrlen(const char *sp);

extern char *slstrncpy(char *destp, const char *srcp, uint32 length);
extern char *slstrncat(char *destp, const char *srcp, uint32 length);

extern void slstrtrim(char* str, char c);

