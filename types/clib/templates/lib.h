define(`libTMPL_CLIB_NAME', `lib'TMPL_CLIB_NAME)dnl
define(`TMPL_CLIB_NAME', TMPL_CLIB_NAME$1)dnl
/*
  libTMPL_CLIB_NAME - something with TMPL_CLIB_NAME

  Copyright (C) 2021 Someone <someone@example.com>

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
*/

#ifndef TMPL_CLIB_INCLUDE_GUARD
#define TMPL_CLIB_INCLUDE_GUARD

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * TMPL_CLIB_NAME(_ctx)
 *
 * library user context - reads the config and system
 * environment, user variables, allows custom logging
 */
struct TMPL_CLIB_NAME(_ctx);
struct TMPL_CLIB_NAME(_ctx) *TMPL_CLIB_NAME(_ref)(struct TMPL_CLIB_NAME(_ctx) *ctx);
struct TMPL_CLIB_NAME(_ctx) *TMPL_CLIB_NAME(_unref)(struct TMPL_CLIB_NAME(_ctx) *ctx);
int TMPL_CLIB_NAME(_new)(struct TMPL_CLIB_NAME(_ctx) **ctx);
void TMPL_CLIB_NAME(_set_log_fn)(struct TMPL_CLIB_NAME(_ctx) *ctx,
                  void (*log_fn)(struct TMPL_CLIB_NAME(_ctx) *ctx,
                                 int priority, const char *file, int line, const char *fn,
                                 const char *format, va_list args));
int TMPL_CLIB_NAME(_get_log_priority)(struct TMPL_CLIB_NAME(_ctx) *ctx);
void TMPL_CLIB_NAME(_set_log_priority)(struct TMPL_CLIB_NAME(_ctx) *ctx, int priority);
void *TMPL_CLIB_NAME(_get_userdata)(struct TMPL_CLIB_NAME(_ctx) *ctx);
void TMPL_CLIB_NAME(_set_userdata)(struct TMPL_CLIB_NAME(_ctx) *ctx, void *userdata);

/*
 * TMPL_CLIB_NAME(_list)
 *
 * access to TMPL_CLIB_NAME generated lists
 */
struct TMPL_CLIB_NAME(_list_entry);
struct TMPL_CLIB_NAME(_list_entry) *TMPL_CLIB_NAME(_list_entry_get_next)(struct TMPL_CLIB_NAME(_list_entry) *list_entry);
const char *TMPL_CLIB_NAME(_list_entry_get_name)(struct TMPL_CLIB_NAME(_list_entry) *list_entry);
const char *TMPL_CLIB_NAME(_list_entry_get_value)(struct TMPL_CLIB_NAME(_list_entry) *list_entry);
#define TMPL_CLIB_NAME(_list_entry_foreach)(list_entry, first_entry) \
        for (list_entry = first_entry; \
             list_entry != NULL; \
             list_entry = TMPL_CLIB_NAME(_list_entry_get_next)(list_entry))

/*
 * TMPL_CLIB_NAME(_thing)
 *
 * access to things of TMPL_CLIB_NAME
 */
struct TMPL_CLIB_NAME(_thing);
struct TMPL_CLIB_NAME(_thing) *TMPL_CLIB_NAME(_thing_ref)(struct TMPL_CLIB_NAME(_thing) *thing);
struct TMPL_CLIB_NAME(_thing) *TMPL_CLIB_NAME(_thing_unref)(struct TMPL_CLIB_NAME(_thing) *thing);
struct TMPL_CLIB_NAME(_ctx) *TMPL_CLIB_NAME(_thing_get_ctx)(struct TMPL_CLIB_NAME(_thing) *thing);
int TMPL_CLIB_NAME(_thing_new_from_string)(struct TMPL_CLIB_NAME(_ctx) *ctx, const char *string, struct TMPL_CLIB_NAME(_thing) **thing);
struct TMPL_CLIB_NAME(_list_entry) *TMPL_CLIB_NAME(_thing_get_some_list_entry)(struct TMPL_CLIB_NAME(_thing) *thing);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  // TMPL_CLIB_INCLUDE_GUARD

