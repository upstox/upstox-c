/*
 * ipo_timeline.h
 *
 * 
 */

#ifndef _ipo_timeline_H_
#define _ipo_timeline_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ipo_timeline_t ipo_timeline_t;




typedef struct ipo_timeline_t {
    char *pre_apply_start_date; // string
    char *application_start_date; // string
    char *application_end_date; // string
    char *allotment_start_date; // string
    char *allotment_date; // string
    char *refund_initiation_date; // string
    char *listing_date; // string
    char *mandate_end_date; // string

    int _library_owned; // Is the library responsible for freeing this object?
} ipo_timeline_t;

ipo_timeline_t *ipo_timeline_create(
    char *pre_apply_start_date,
    char *application_start_date,
    char *application_end_date,
    char *allotment_start_date,
    char *allotment_date,
    char *refund_initiation_date,
    char *listing_date,
    char *mandate_end_date
);

void ipo_timeline_free(ipo_timeline_t *ipo_timeline);

ipo_timeline_t *ipo_timeline_parseFromJSON(cJSON *ipo_timelineJSON);

cJSON *ipo_timeline_convertToJSON(ipo_timeline_t *ipo_timeline);

#endif /* _ipo_timeline_H_ */

