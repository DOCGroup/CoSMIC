/* u_concat.c:  Invalid pp-token generated by ## operator.  */

/* { dg-do preprocess } */

#define _VARIANT_BOOL   /##/
/*
 *   The following line intends to be commented out.  '//' generated by the
 * macro is, however, not a valid pp-token.  Since any comment is removed
 * before macro definition or macro expansion, a comment is never generated
 * by macro.
 */
    _VARIANT_BOOL bool; /* { dg-error "does not give a valid preprocessing token| Not a valid preprocessing token" }   */

