#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipo_timeline.h"



static ipo_timeline_t *ipo_timeline_create_internal(
    char *pre_apply_start_date,
    char *application_start_date,
    char *application_end_date,
    char *allotment_start_date,
    char *allotment_date,
    char *refund_initiation_date,
    char *listing_date,
    char *mandate_end_date
    ) {
    ipo_timeline_t *ipo_timeline_local_var = malloc(sizeof(ipo_timeline_t));
    if (!ipo_timeline_local_var) {
        return NULL;
    }
    memset(ipo_timeline_local_var, 0, sizeof(ipo_timeline_t));
    ipo_timeline_local_var->_library_owned = 1;
    ipo_timeline_local_var->pre_apply_start_date = pre_apply_start_date;
    ipo_timeline_local_var->application_start_date = application_start_date;
    ipo_timeline_local_var->application_end_date = application_end_date;
    ipo_timeline_local_var->allotment_start_date = allotment_start_date;
    ipo_timeline_local_var->allotment_date = allotment_date;
    ipo_timeline_local_var->refund_initiation_date = refund_initiation_date;
    ipo_timeline_local_var->listing_date = listing_date;
    ipo_timeline_local_var->mandate_end_date = mandate_end_date;
    return ipo_timeline_local_var;
}

ipo_timeline_t *ipo_timeline_create(
    char *pre_apply_start_date,
    char *application_start_date,
    char *application_end_date,
    char *allotment_start_date,
    char *allotment_date,
    char *refund_initiation_date,
    char *listing_date,
    char *mandate_end_date
    ) {
    ipo_timeline_t *result = ipo_timeline_create_internal (
        pre_apply_start_date,
        application_start_date,
        application_end_date,
        allotment_start_date,
        allotment_date,
        refund_initiation_date,
        listing_date,
        mandate_end_date
        );
    if (!result) {
    }
    return result;
}

void ipo_timeline_free(ipo_timeline_t *ipo_timeline) {
    if(NULL == ipo_timeline){
        return ;
    }
    if(ipo_timeline->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ipo_timeline_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ipo_timeline->pre_apply_start_date) {
        free(ipo_timeline->pre_apply_start_date);
        ipo_timeline->pre_apply_start_date = NULL;
    }
    if (ipo_timeline->application_start_date) {
        free(ipo_timeline->application_start_date);
        ipo_timeline->application_start_date = NULL;
    }
    if (ipo_timeline->application_end_date) {
        free(ipo_timeline->application_end_date);
        ipo_timeline->application_end_date = NULL;
    }
    if (ipo_timeline->allotment_start_date) {
        free(ipo_timeline->allotment_start_date);
        ipo_timeline->allotment_start_date = NULL;
    }
    if (ipo_timeline->allotment_date) {
        free(ipo_timeline->allotment_date);
        ipo_timeline->allotment_date = NULL;
    }
    if (ipo_timeline->refund_initiation_date) {
        free(ipo_timeline->refund_initiation_date);
        ipo_timeline->refund_initiation_date = NULL;
    }
    if (ipo_timeline->listing_date) {
        free(ipo_timeline->listing_date);
        ipo_timeline->listing_date = NULL;
    }
    if (ipo_timeline->mandate_end_date) {
        free(ipo_timeline->mandate_end_date);
        ipo_timeline->mandate_end_date = NULL;
    }
    free(ipo_timeline);
}

cJSON *ipo_timeline_convertToJSON(ipo_timeline_t *ipo_timeline) {
    cJSON *item = cJSON_CreateObject();

    // ipo_timeline->pre_apply_start_date
    if(ipo_timeline->pre_apply_start_date) {
    if(cJSON_AddStringToObject(item, "pre_apply_start_date", ipo_timeline->pre_apply_start_date) == NULL) {
    goto fail; //String
    }
    }


    // ipo_timeline->application_start_date
    if(ipo_timeline->application_start_date) {
    if(cJSON_AddStringToObject(item, "application_start_date", ipo_timeline->application_start_date) == NULL) {
    goto fail; //String
    }
    }


    // ipo_timeline->application_end_date
    if(ipo_timeline->application_end_date) {
    if(cJSON_AddStringToObject(item, "application_end_date", ipo_timeline->application_end_date) == NULL) {
    goto fail; //String
    }
    }


    // ipo_timeline->allotment_start_date
    if(ipo_timeline->allotment_start_date) {
    if(cJSON_AddStringToObject(item, "allotment_start_date", ipo_timeline->allotment_start_date) == NULL) {
    goto fail; //String
    }
    }


    // ipo_timeline->allotment_date
    if(ipo_timeline->allotment_date) {
    if(cJSON_AddStringToObject(item, "allotment_date", ipo_timeline->allotment_date) == NULL) {
    goto fail; //String
    }
    }


    // ipo_timeline->refund_initiation_date
    if(ipo_timeline->refund_initiation_date) {
    if(cJSON_AddStringToObject(item, "refund_initiation_date", ipo_timeline->refund_initiation_date) == NULL) {
    goto fail; //String
    }
    }


    // ipo_timeline->listing_date
    if(ipo_timeline->listing_date) {
    if(cJSON_AddStringToObject(item, "listing_date", ipo_timeline->listing_date) == NULL) {
    goto fail; //String
    }
    }


    // ipo_timeline->mandate_end_date
    if(ipo_timeline->mandate_end_date) {
    if(cJSON_AddStringToObject(item, "mandate_end_date", ipo_timeline->mandate_end_date) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ipo_timeline_t *ipo_timeline_parseFromJSON(cJSON *ipo_timelineJSON){

    ipo_timeline_t *ipo_timeline_local_var = NULL;

    char *pre_apply_start_date_local_str = NULL;

    char *application_start_date_local_str = NULL;

    char *application_end_date_local_str = NULL;

    char *allotment_start_date_local_str = NULL;

    char *allotment_date_local_str = NULL;

    char *refund_initiation_date_local_str = NULL;

    char *listing_date_local_str = NULL;

    char *mandate_end_date_local_str = NULL;

    // ipo_timeline->pre_apply_start_date
    cJSON *pre_apply_start_date = cJSON_GetObjectItemCaseSensitive(ipo_timelineJSON, "pre_apply_start_date");
    if (cJSON_IsNull(pre_apply_start_date)) {
        pre_apply_start_date = NULL;
    }
    if (pre_apply_start_date) { 
    if(!cJSON_IsString(pre_apply_start_date) && !cJSON_IsNull(pre_apply_start_date))
    {
    goto end; //String
    }
    }

    // ipo_timeline->application_start_date
    cJSON *application_start_date = cJSON_GetObjectItemCaseSensitive(ipo_timelineJSON, "application_start_date");
    if (cJSON_IsNull(application_start_date)) {
        application_start_date = NULL;
    }
    if (application_start_date) { 
    if(!cJSON_IsString(application_start_date) && !cJSON_IsNull(application_start_date))
    {
    goto end; //String
    }
    }

    // ipo_timeline->application_end_date
    cJSON *application_end_date = cJSON_GetObjectItemCaseSensitive(ipo_timelineJSON, "application_end_date");
    if (cJSON_IsNull(application_end_date)) {
        application_end_date = NULL;
    }
    if (application_end_date) { 
    if(!cJSON_IsString(application_end_date) && !cJSON_IsNull(application_end_date))
    {
    goto end; //String
    }
    }

    // ipo_timeline->allotment_start_date
    cJSON *allotment_start_date = cJSON_GetObjectItemCaseSensitive(ipo_timelineJSON, "allotment_start_date");
    if (cJSON_IsNull(allotment_start_date)) {
        allotment_start_date = NULL;
    }
    if (allotment_start_date) { 
    if(!cJSON_IsString(allotment_start_date) && !cJSON_IsNull(allotment_start_date))
    {
    goto end; //String
    }
    }

    // ipo_timeline->allotment_date
    cJSON *allotment_date = cJSON_GetObjectItemCaseSensitive(ipo_timelineJSON, "allotment_date");
    if (cJSON_IsNull(allotment_date)) {
        allotment_date = NULL;
    }
    if (allotment_date) { 
    if(!cJSON_IsString(allotment_date) && !cJSON_IsNull(allotment_date))
    {
    goto end; //String
    }
    }

    // ipo_timeline->refund_initiation_date
    cJSON *refund_initiation_date = cJSON_GetObjectItemCaseSensitive(ipo_timelineJSON, "refund_initiation_date");
    if (cJSON_IsNull(refund_initiation_date)) {
        refund_initiation_date = NULL;
    }
    if (refund_initiation_date) { 
    if(!cJSON_IsString(refund_initiation_date) && !cJSON_IsNull(refund_initiation_date))
    {
    goto end; //String
    }
    }

    // ipo_timeline->listing_date
    cJSON *listing_date = cJSON_GetObjectItemCaseSensitive(ipo_timelineJSON, "listing_date");
    if (cJSON_IsNull(listing_date)) {
        listing_date = NULL;
    }
    if (listing_date) { 
    if(!cJSON_IsString(listing_date) && !cJSON_IsNull(listing_date))
    {
    goto end; //String
    }
    }

    // ipo_timeline->mandate_end_date
    cJSON *mandate_end_date = cJSON_GetObjectItemCaseSensitive(ipo_timelineJSON, "mandate_end_date");
    if (cJSON_IsNull(mandate_end_date)) {
        mandate_end_date = NULL;
    }
    if (mandate_end_date) { 
    if(!cJSON_IsString(mandate_end_date) && !cJSON_IsNull(mandate_end_date))
    {
    goto end; //String
    }
    }


    if (pre_apply_start_date && !cJSON_IsNull(pre_apply_start_date)) pre_apply_start_date_local_str = strdup(pre_apply_start_date->valuestring);
    if (application_start_date && !cJSON_IsNull(application_start_date)) application_start_date_local_str = strdup(application_start_date->valuestring);
    if (application_end_date && !cJSON_IsNull(application_end_date)) application_end_date_local_str = strdup(application_end_date->valuestring);
    if (allotment_start_date && !cJSON_IsNull(allotment_start_date)) allotment_start_date_local_str = strdup(allotment_start_date->valuestring);
    if (allotment_date && !cJSON_IsNull(allotment_date)) allotment_date_local_str = strdup(allotment_date->valuestring);
    if (refund_initiation_date && !cJSON_IsNull(refund_initiation_date)) refund_initiation_date_local_str = strdup(refund_initiation_date->valuestring);
    if (listing_date && !cJSON_IsNull(listing_date)) listing_date_local_str = strdup(listing_date->valuestring);
    if (mandate_end_date && !cJSON_IsNull(mandate_end_date)) mandate_end_date_local_str = strdup(mandate_end_date->valuestring);

    ipo_timeline_local_var = ipo_timeline_create_internal (
        pre_apply_start_date_local_str,
        application_start_date_local_str,
        application_end_date_local_str,
        allotment_start_date_local_str,
        allotment_date_local_str,
        refund_initiation_date_local_str,
        listing_date_local_str,
        mandate_end_date_local_str
        );

    if (!ipo_timeline_local_var) {
        goto end;
    }

    return ipo_timeline_local_var;
end:
    if (pre_apply_start_date_local_str) {
        free(pre_apply_start_date_local_str);
        pre_apply_start_date_local_str = NULL;
    }
    if (application_start_date_local_str) {
        free(application_start_date_local_str);
        application_start_date_local_str = NULL;
    }
    if (application_end_date_local_str) {
        free(application_end_date_local_str);
        application_end_date_local_str = NULL;
    }
    if (allotment_start_date_local_str) {
        free(allotment_start_date_local_str);
        allotment_start_date_local_str = NULL;
    }
    if (allotment_date_local_str) {
        free(allotment_date_local_str);
        allotment_date_local_str = NULL;
    }
    if (refund_initiation_date_local_str) {
        free(refund_initiation_date_local_str);
        refund_initiation_date_local_str = NULL;
    }
    if (listing_date_local_str) {
        free(listing_date_local_str);
        listing_date_local_str = NULL;
    }
    if (mandate_end_date_local_str) {
        free(mandate_end_date_local_str);
        mandate_end_date_local_str = NULL;
    }
    return NULL;

}
