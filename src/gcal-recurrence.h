/* -*- mode: c; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/*
 * gcal-recurrence.h
 * Copyright (C) 2017 Yash Singh <yashdev10p@gmail.com>
 *
 * gnome-calendar is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * gnome-calendar is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GCAL_RECURRENCE_H
#define GCAL_RECURRENCE_H

#include <glib-object.h>
#include <libecal/libecal.h>

G_BEGIN_DECLS

#define GCAL_TYPE_RECURRENCE (gcal_recurrence_get_type())

typedef struct _GcalRecurrence GcalRecurrence;

typedef enum
{
  GCAL_RECURRENCE_NO_REPEAT,
  GCAL_RECURRENCE_DAILY,
  GCAL_RECURRENCE_MON_FRI,
  GCAL_RECURRENCE_WEEKLY,
  GCAL_RECURRENCE_MONTHLY,
  GCAL_RECURRENCE_YEARLY,
  GCAL_RECURRENCE_OTHER
} GcalRecurrenceFrequency;

typedef enum
{
  GCAL_RECURRENCE_FOREVER,
  GCAL_RECURRENCE_COUNT,
  GCAL_RECURRENCE_UNTIL
} GcalRecurrenceLimitType;

struct _GcalRecurrence
{
  GcalRecurrenceFrequency  frequency;
  GcalRecurrenceLimitType  limit_type;

  struct {
    GDateTime *until; 
    guint count; 
  } limit;

};

GType                gcal_recurrence_get_type                    (void) G_GNUC_CONST;

GcalRecurrence*      gcal_recurrence_new                         (void);

GcalRecurrence*      gcal_recurrence_copy                        (GcalRecurrence *recur);

void                 gcal_recurrence_free                        (GcalRecurrence *recur);

GcalRecurrence*      gcal_recurrence_parse_recurrence_rules      (ECalComponent *comp);

struct icalrecurrencetype*    gcal_recurrence_to_rrule           (GcalRecurrence *recur);

G_END_DECLS

#endif /* GCAL_RECURRENCE_H */
