#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ohlc_v3.h"



static ohlc_v3_t *ohlc_v3_create_internal(
    double *open,
    double *high,
    double *low,
    double *close,
    long *volume,
    long *ts
    ) {
    ohlc_v3_t *ohlc_v3_local_var = malloc(sizeof(ohlc_v3_t));
    if (!ohlc_v3_local_var) {
        return NULL;
    }
    memset(ohlc_v3_local_var, 0, sizeof(ohlc_v3_t));
    ohlc_v3_local_var->_library_owned = 1;
    ohlc_v3_local_var->open = open;
    ohlc_v3_local_var->high = high;
    ohlc_v3_local_var->low = low;
    ohlc_v3_local_var->close = close;
    ohlc_v3_local_var->volume = volume;
    ohlc_v3_local_var->ts = ts;
    return ohlc_v3_local_var;
}

ohlc_v3_t *ohlc_v3_create(
    double *open,
    double *high,
    double *low,
    double *close,
    long *volume,
    long *ts
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
    long *volume_copy = NULL;
    if (volume) {
        volume_copy = malloc(sizeof(long));
        if (volume_copy) *volume_copy = *volume;
    }
    long *ts_copy = NULL;
    if (ts) {
        ts_copy = malloc(sizeof(long));
        if (ts_copy) *ts_copy = *ts;
    }
    ohlc_v3_t *result = ohlc_v3_create_internal (
        open_copy,
        high_copy,
        low_copy,
        close_copy,
        volume_copy,
        ts_copy
        );
    if (!result) {
        free(open_copy);
        free(high_copy);
        free(low_copy);
        free(close_copy);
        free(volume_copy);
        free(ts_copy);
    }
    return result;
}

void ohlc_v3_free(ohlc_v3_t *ohlc_v3) {
    if(NULL == ohlc_v3){
        return ;
    }
    if(ohlc_v3->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ohlc_v3_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ohlc_v3->open) {
        free(ohlc_v3->open);
        ohlc_v3->open = NULL;
    }
    if (ohlc_v3->high) {
        free(ohlc_v3->high);
        ohlc_v3->high = NULL;
    }
    if (ohlc_v3->low) {
        free(ohlc_v3->low);
        ohlc_v3->low = NULL;
    }
    if (ohlc_v3->close) {
        free(ohlc_v3->close);
        ohlc_v3->close = NULL;
    }
    if (ohlc_v3->volume) {
        free(ohlc_v3->volume);
        ohlc_v3->volume = NULL;
    }
    if (ohlc_v3->ts) {
        free(ohlc_v3->ts);
        ohlc_v3->ts = NULL;
    }
    free(ohlc_v3);
}

cJSON *ohlc_v3_convertToJSON(ohlc_v3_t *ohlc_v3) {
    cJSON *item = cJSON_CreateObject();

    // ohlc_v3->open
    if(ohlc_v3->open) {
    if(cJSON_AddNumberToObject(item, "open", *ohlc_v3->open) == NULL) {
    goto fail; //Numeric
    }
    }


    // ohlc_v3->high
    if(ohlc_v3->high) {
    if(cJSON_AddNumberToObject(item, "high", *ohlc_v3->high) == NULL) {
    goto fail; //Numeric
    }
    }


    // ohlc_v3->low
    if(ohlc_v3->low) {
    if(cJSON_AddNumberToObject(item, "low", *ohlc_v3->low) == NULL) {
    goto fail; //Numeric
    }
    }


    // ohlc_v3->close
    if(ohlc_v3->close) {
    if(cJSON_AddNumberToObject(item, "close", *ohlc_v3->close) == NULL) {
    goto fail; //Numeric
    }
    }


    // ohlc_v3->volume
    if(ohlc_v3->volume) {
    if(cJSON_AddNumberToObject(item, "volume", *ohlc_v3->volume) == NULL) {
    goto fail; //Numeric
    }
    }


    // ohlc_v3->ts
    if(ohlc_v3->ts) {
    if(cJSON_AddNumberToObject(item, "ts", *ohlc_v3->ts) == NULL) {
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

ohlc_v3_t *ohlc_v3_parseFromJSON(cJSON *ohlc_v3JSON){

    ohlc_v3_t *ohlc_v3_local_var = NULL;

    // define the local variable for ohlc_v3->open
    double *open_local_var = NULL;

    // define the local variable for ohlc_v3->high
    double *high_local_var = NULL;

    // define the local variable for ohlc_v3->low
    double *low_local_var = NULL;

    // define the local variable for ohlc_v3->close
    double *close_local_var = NULL;

    // define the local variable for ohlc_v3->volume
    long *volume_local_var = NULL;

    // define the local variable for ohlc_v3->ts
    long *ts_local_var = NULL;

    // ohlc_v3->open
    cJSON *open = cJSON_GetObjectItemCaseSensitive(ohlc_v3JSON, "open");
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

    // ohlc_v3->high
    cJSON *high = cJSON_GetObjectItemCaseSensitive(ohlc_v3JSON, "high");
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

    // ohlc_v3->low
    cJSON *low = cJSON_GetObjectItemCaseSensitive(ohlc_v3JSON, "low");
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

    // ohlc_v3->close
    cJSON *close = cJSON_GetObjectItemCaseSensitive(ohlc_v3JSON, "close");
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

    // ohlc_v3->volume
    cJSON *volume = cJSON_GetObjectItemCaseSensitive(ohlc_v3JSON, "volume");
    if (cJSON_IsNull(volume)) {
        volume = NULL;
    }
    if (volume) { 
    if(!cJSON_IsNumber(volume))
    {
    goto end; //Numeric
    }
    volume_local_var = malloc(sizeof(long));
    if(!volume_local_var)
    {
        goto end;
    }
    *volume_local_var = volume->valuedouble;
    }

    // ohlc_v3->ts
    cJSON *ts = cJSON_GetObjectItemCaseSensitive(ohlc_v3JSON, "ts");
    if (cJSON_IsNull(ts)) {
        ts = NULL;
    }
    if (ts) { 
    if(!cJSON_IsNumber(ts))
    {
    goto end; //Numeric
    }
    ts_local_var = malloc(sizeof(long));
    if(!ts_local_var)
    {
        goto end;
    }
    *ts_local_var = ts->valuedouble;
    }



    ohlc_v3_local_var = ohlc_v3_create_internal (
        open_local_var,
        high_local_var,
        low_local_var,
        close_local_var,
        volume_local_var,
        ts_local_var
        );

    if (!ohlc_v3_local_var) {
        goto end;
    }

    return ohlc_v3_local_var;
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
    if (volume_local_var) {
        free(volume_local_var);
        volume_local_var = NULL;
    }
    if (ts_local_var) {
        free(ts_local_var);
        ts_local_var = NULL;
    }
    return NULL;

}
