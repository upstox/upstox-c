#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ohlc.h"



static ohlc_t *ohlc_create_internal(
    double *open,
    double *high,
    double *low,
    double *close
    ) {
    ohlc_t *ohlc_local_var = malloc(sizeof(ohlc_t));
    if (!ohlc_local_var) {
        return NULL;
    }
    memset(ohlc_local_var, 0, sizeof(ohlc_t));
    ohlc_local_var->_library_owned = 1;
    ohlc_local_var->open = open;
    ohlc_local_var->high = high;
    ohlc_local_var->low = low;
    ohlc_local_var->close = close;
    return ohlc_local_var;
}

ohlc_t *ohlc_create(
    double *open,
    double *high,
    double *low,
    double *close
    ) {
    double *open_copy = NULL;
    if (open) {
        open_copy = malloc(sizeof(double));
        if (open_copy) *open_copy = *open;
    }
    double *high_copy = NULL;
    if (high) {
        high_copy = malloc(sizeof(double));
        if (high_copy) *high_copy = *high;
    }
    double *low_copy = NULL;
    if (low) {
        low_copy = malloc(sizeof(double));
        if (low_copy) *low_copy = *low;
    }
    double *close_copy = NULL;
    if (close) {
        close_copy = malloc(sizeof(double));
        if (close_copy) *close_copy = *close;
    }
    ohlc_t *result = ohlc_create_internal (
        open_copy,
        high_copy,
        low_copy,
        close_copy
        );
    if (!result) {
        free(open_copy);
        free(high_copy);
        free(low_copy);
        free(close_copy);
    }
    return result;
}

void ohlc_free(ohlc_t *ohlc) {
    if(NULL == ohlc){
        return ;
    }
    if(ohlc->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ohlc_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ohlc->open) {
        free(ohlc->open);
        ohlc->open = NULL;
    }
    if (ohlc->high) {
        free(ohlc->high);
        ohlc->high = NULL;
    }
    if (ohlc->low) {
        free(ohlc->low);
        ohlc->low = NULL;
    }
    if (ohlc->close) {
        free(ohlc->close);
        ohlc->close = NULL;
    }
    free(ohlc);
}

cJSON *ohlc_convertToJSON(ohlc_t *ohlc) {
    cJSON *item = cJSON_CreateObject();

    // ohlc->open
    if(ohlc->open) {
    if(cJSON_AddNumberToObject(item, "open", *ohlc->open) == NULL) {
    goto fail; //Numeric
    }
    }


    // ohlc->high
    if(ohlc->high) {
    if(cJSON_AddNumberToObject(item, "high", *ohlc->high) == NULL) {
    goto fail; //Numeric
    }
    }


    // ohlc->low
    if(ohlc->low) {
    if(cJSON_AddNumberToObject(item, "low", *ohlc->low) == NULL) {
    goto fail; //Numeric
    }
    }


    // ohlc->close
    if(ohlc->close) {
    if(cJSON_AddNumberToObject(item, "close", *ohlc->close) == NULL) {
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

ohlc_t *ohlc_parseFromJSON(cJSON *ohlcJSON){

    ohlc_t *ohlc_local_var = NULL;

    // define the local variable for ohlc->open
    double *open_local_var = NULL;

    // define the local variable for ohlc->high
    double *high_local_var = NULL;

    // define the local variable for ohlc->low
    double *low_local_var = NULL;

    // define the local variable for ohlc->close
    double *close_local_var = NULL;

    // ohlc->open
    cJSON *open = cJSON_GetObjectItemCaseSensitive(ohlcJSON, "open");
    if (cJSON_IsNull(open)) {
        open = NULL;
    }
    if (open) { 
    if(!cJSON_IsNumber(open))
    {
    goto end; //Numeric
    }
    open_local_var = malloc(sizeof(double));
    if(!open_local_var)
    {
        goto end;
    }
    *open_local_var = open->valuedouble;
    }

    // ohlc->high
    cJSON *high = cJSON_GetObjectItemCaseSensitive(ohlcJSON, "high");
    if (cJSON_IsNull(high)) {
        high = NULL;
    }
    if (high) { 
    if(!cJSON_IsNumber(high))
    {
    goto end; //Numeric
    }
    high_local_var = malloc(sizeof(double));
    if(!high_local_var)
    {
        goto end;
    }
    *high_local_var = high->valuedouble;
    }

    // ohlc->low
    cJSON *low = cJSON_GetObjectItemCaseSensitive(ohlcJSON, "low");
    if (cJSON_IsNull(low)) {
        low = NULL;
    }
    if (low) { 
    if(!cJSON_IsNumber(low))
    {
    goto end; //Numeric
    }
    low_local_var = malloc(sizeof(double));
    if(!low_local_var)
    {
        goto end;
    }
    *low_local_var = low->valuedouble;
    }

    // ohlc->close
    cJSON *close = cJSON_GetObjectItemCaseSensitive(ohlcJSON, "close");
    if (cJSON_IsNull(close)) {
        close = NULL;
    }
    if (close) { 
    if(!cJSON_IsNumber(close))
    {
    goto end; //Numeric
    }
    close_local_var = malloc(sizeof(double));
    if(!close_local_var)
    {
        goto end;
    }
    *close_local_var = close->valuedouble;
    }



    ohlc_local_var = ohlc_create_internal (
        open_local_var,
        high_local_var,
        low_local_var,
        close_local_var
        );

    if (!ohlc_local_var) {
        goto end;
    }

    return ohlc_local_var;
end:
    if (open_local_var) {
        free(open_local_var);
        open_local_var = NULL;
    }
    if (high_local_var) {
        free(high_local_var);
        high_local_var = NULL;
    }
    if (low_local_var) {
        free(low_local_var);
        low_local_var = NULL;
    }
    if (close_local_var) {
        free(close_local_var);
        close_local_var = NULL;
    }
    return NULL;

}
