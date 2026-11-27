#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "brokerage_taxes.h"



static brokerage_taxes_t *brokerage_taxes_create_internal(
    double *gst,
    double *stt,
    double *stamp_duty
    ) {
    brokerage_taxes_t *brokerage_taxes_local_var = malloc(sizeof(brokerage_taxes_t));
    if (!brokerage_taxes_local_var) {
        return NULL;
    }
    memset(brokerage_taxes_local_var, 0, sizeof(brokerage_taxes_t));
    brokerage_taxes_local_var->_library_owned = 1;
    brokerage_taxes_local_var->gst = gst;
    brokerage_taxes_local_var->stt = stt;
    brokerage_taxes_local_var->stamp_duty = stamp_duty;
    return brokerage_taxes_local_var;
}

brokerage_taxes_t *brokerage_taxes_create(
    double *gst,
    double *stt,
    double *stamp_duty
    ) {
    double *gst_copy = NULL;
    if (gst) {
        gst_copy = malloc(sizeof(double));
        if (gst_copy) *gst_copy = *gst;
    }
    double *stt_copy = NULL;
    if (stt) {
        stt_copy = malloc(sizeof(double));
        if (stt_copy) *stt_copy = *stt;
    }
    double *stamp_duty_copy = NULL;
    if (stamp_duty) {
        stamp_duty_copy = malloc(sizeof(double));
        if (stamp_duty_copy) *stamp_duty_copy = *stamp_duty;
    }
    brokerage_taxes_t *result = brokerage_taxes_create_internal (
        gst_copy,
        stt_copy,
        stamp_duty_copy
        );
    if (!result) {
        free(gst_copy);
        free(stt_copy);
        free(stamp_duty_copy);
    }
    return result;
}

void brokerage_taxes_free(brokerage_taxes_t *brokerage_taxes) {
    if(NULL == brokerage_taxes){
        return ;
    }
    if(brokerage_taxes->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "brokerage_taxes_free");
        return ;
    }
    listEntry_t *listEntry;
    if (brokerage_taxes->gst) {
        free(brokerage_taxes->gst);
        brokerage_taxes->gst = NULL;
    }
    if (brokerage_taxes->stt) {
        free(brokerage_taxes->stt);
        brokerage_taxes->stt = NULL;
    }
    if (brokerage_taxes->stamp_duty) {
        free(brokerage_taxes->stamp_duty);
        brokerage_taxes->stamp_duty = NULL;
    }
    free(brokerage_taxes);
}

cJSON *brokerage_taxes_convertToJSON(brokerage_taxes_t *brokerage_taxes) {
    cJSON *item = cJSON_CreateObject();

    // brokerage_taxes->gst
    if(brokerage_taxes->gst) {
    if(cJSON_AddNumberToObject(item, "gst", *brokerage_taxes->gst) == NULL) {
    goto fail; //Numeric
    }
    }


    // brokerage_taxes->stt
    if(brokerage_taxes->stt) {
    if(cJSON_AddNumberToObject(item, "stt", *brokerage_taxes->stt) == NULL) {
    goto fail; //Numeric
    }
    }


    // brokerage_taxes->stamp_duty
    if(brokerage_taxes->stamp_duty) {
    if(cJSON_AddNumberToObject(item, "stamp_duty", *brokerage_taxes->stamp_duty) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

brokerage_taxes_t *brokerage_taxes_parseFromJSON(cJSON *brokerage_taxesJSON){

    brokerage_taxes_t *brokerage_taxes_local_var = NULL;

    // define the local variable for brokerage_taxes->gst
    double *gst_local_var = NULL;

    // define the local variable for brokerage_taxes->stt
    double *stt_local_var = NULL;

    // define the local variable for brokerage_taxes->stamp_duty
    double *stamp_duty_local_var = NULL;

    // brokerage_taxes->gst
    cJSON *gst = cJSON_GetObjectItemCaseSensitive(brokerage_taxesJSON, "gst");
    if (cJSON_IsNull(gst)) {
        gst = NULL;
    }
    if (gst) { 
    if(!cJSON_IsNumber(gst))
    {
    goto end; //Numeric
    }
    gst_local_var = malloc(sizeof(double));
    if(!gst_local_var)
    {
        goto end;
    }
    *gst_local_var = gst->valuedouble;
    }

    // brokerage_taxes->stt
    cJSON *stt = cJSON_GetObjectItemCaseSensitive(brokerage_taxesJSON, "stt");
    if (cJSON_IsNull(stt)) {
        stt = NULL;
    }
    if (stt) { 
    if(!cJSON_IsNumber(stt))
    {
    goto end; //Numeric
    }
    stt_local_var = malloc(sizeof(double));
    if(!stt_local_var)
    {
        goto end;
    }
    *stt_local_var = stt->valuedouble;
    }

    // brokerage_taxes->stamp_duty
    cJSON *stamp_duty = cJSON_GetObjectItemCaseSensitive(brokerage_taxesJSON, "stamp_duty");
    if (cJSON_IsNull(stamp_duty)) {
        stamp_duty = NULL;
    }
    if (stamp_duty) { 
    if(!cJSON_IsNumber(stamp_duty))
    {
    goto end; //Numeric
    }
    stamp_duty_local_var = malloc(sizeof(double));
    if(!stamp_duty_local_var)
    {
        goto end;
    }
    *stamp_duty_local_var = stamp_duty->valuedouble;
    }



    brokerage_taxes_local_var = brokerage_taxes_create_internal (
        gst_local_var,
        stt_local_var,
        stamp_duty_local_var
        );

    if (!brokerage_taxes_local_var) {
        goto end;
    }

    return brokerage_taxes_local_var;
end:
    if (gst_local_var) {
        free(gst_local_var);
        gst_local_var = NULL;
    }
    if (stt_local_var) {
        free(stt_local_var);
        stt_local_var = NULL;
    }
    if (stamp_duty_local_var) {
        free(stamp_duty_local_var);
        stamp_duty_local_var = NULL;
    }
    return NULL;

}
