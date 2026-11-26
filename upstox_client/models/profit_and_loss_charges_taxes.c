#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "profit_and_loss_charges_taxes.h"



static profit_and_loss_charges_taxes_t *profit_and_loss_charges_taxes_create_internal(
    double *gst,
    double *stt,
    double *stamp_duty
    ) {
    profit_and_loss_charges_taxes_t *profit_and_loss_charges_taxes_local_var = malloc(sizeof(profit_and_loss_charges_taxes_t));
    if (!profit_and_loss_charges_taxes_local_var) {
        return NULL;
    }
    memset(profit_and_loss_charges_taxes_local_var, 0, sizeof(profit_and_loss_charges_taxes_t));
    profit_and_loss_charges_taxes_local_var->_library_owned = 1;
    profit_and_loss_charges_taxes_local_var->gst = gst;
    profit_and_loss_charges_taxes_local_var->stt = stt;
    profit_and_loss_charges_taxes_local_var->stamp_duty = stamp_duty;
    return profit_and_loss_charges_taxes_local_var;
}

profit_and_loss_charges_taxes_t *profit_and_loss_charges_taxes_create(
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
    profit_and_loss_charges_taxes_t *result = profit_and_loss_charges_taxes_create_internal (
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

void profit_and_loss_charges_taxes_free(profit_and_loss_charges_taxes_t *profit_and_loss_charges_taxes) {
    if(NULL == profit_and_loss_charges_taxes){
        return ;
    }
    if(profit_and_loss_charges_taxes->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "profit_and_loss_charges_taxes_free");
        return ;
    }
    listEntry_t *listEntry;
    if (profit_and_loss_charges_taxes->gst) {
        free(profit_and_loss_charges_taxes->gst);
        profit_and_loss_charges_taxes->gst = NULL;
    }
    if (profit_and_loss_charges_taxes->stt) {
        free(profit_and_loss_charges_taxes->stt);
        profit_and_loss_charges_taxes->stt = NULL;
    }
    if (profit_and_loss_charges_taxes->stamp_duty) {
        free(profit_and_loss_charges_taxes->stamp_duty);
        profit_and_loss_charges_taxes->stamp_duty = NULL;
    }
    free(profit_and_loss_charges_taxes);
}

cJSON *profit_and_loss_charges_taxes_convertToJSON(profit_and_loss_charges_taxes_t *profit_and_loss_charges_taxes) {
    cJSON *item = cJSON_CreateObject();

    // profit_and_loss_charges_taxes->gst
    if(profit_and_loss_charges_taxes->gst) {
    if(cJSON_AddNumberToObject(item, "gst", *profit_and_loss_charges_taxes->gst) == NULL) {
    goto fail; //Numeric
    }
    }


    // profit_and_loss_charges_taxes->stt
    if(profit_and_loss_charges_taxes->stt) {
    if(cJSON_AddNumberToObject(item, "stt", *profit_and_loss_charges_taxes->stt) == NULL) {
    goto fail; //Numeric
    }
    }


    // profit_and_loss_charges_taxes->stamp_duty
    if(profit_and_loss_charges_taxes->stamp_duty) {
    if(cJSON_AddNumberToObject(item, "stamp_duty", *profit_and_loss_charges_taxes->stamp_duty) == NULL) {
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

profit_and_loss_charges_taxes_t *profit_and_loss_charges_taxes_parseFromJSON(cJSON *profit_and_loss_charges_taxesJSON){

    profit_and_loss_charges_taxes_t *profit_and_loss_charges_taxes_local_var = NULL;

    // define the local variable for profit_and_loss_charges_taxes->gst
    double *gst_local_var = NULL;

    // define the local variable for profit_and_loss_charges_taxes->stt
    double *stt_local_var = NULL;

    // define the local variable for profit_and_loss_charges_taxes->stamp_duty
    double *stamp_duty_local_var = NULL;

    // profit_and_loss_charges_taxes->gst
    cJSON *gst = cJSON_GetObjectItemCaseSensitive(profit_and_loss_charges_taxesJSON, "gst");
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

    // profit_and_loss_charges_taxes->stt
    cJSON *stt = cJSON_GetObjectItemCaseSensitive(profit_and_loss_charges_taxesJSON, "stt");
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

    // profit_and_loss_charges_taxes->stamp_duty
    cJSON *stamp_duty = cJSON_GetObjectItemCaseSensitive(profit_and_loss_charges_taxesJSON, "stamp_duty");
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



    profit_and_loss_charges_taxes_local_var = profit_and_loss_charges_taxes_create_internal (
        gst_local_var,
        stt_local_var,
        stamp_duty_local_var
        );

    if (!profit_and_loss_charges_taxes_local_var) {
        goto end;
    }

    return profit_and_loss_charges_taxes_local_var;
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
