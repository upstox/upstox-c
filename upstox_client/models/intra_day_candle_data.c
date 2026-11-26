#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "intra_day_candle_data.h"



static intra_day_candle_data_t *intra_day_candle_data_create_internal(
    list_t *candles
    ) {
    intra_day_candle_data_t *intra_day_candle_data_local_var = malloc(sizeof(intra_day_candle_data_t));
    if (!intra_day_candle_data_local_var) {
        return NULL;
    }
    memset(intra_day_candle_data_local_var, 0, sizeof(intra_day_candle_data_t));
    intra_day_candle_data_local_var->_library_owned = 1;
    intra_day_candle_data_local_var->candles = candles;
    return intra_day_candle_data_local_var;
}

intra_day_candle_data_t *intra_day_candle_data_create(
    list_t *candles
    ) {
    intra_day_candle_data_t *result = intra_day_candle_data_create_internal (
        candles
        );
    if (!result) {
    }
    return result;
}

void intra_day_candle_data_free(intra_day_candle_data_t *intra_day_candle_data) {
    if(NULL == intra_day_candle_data){
        return ;
    }
    if(intra_day_candle_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "intra_day_candle_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (intra_day_candle_data->candles) {
        list_ForEach(listEntry, intra_day_candle_data->candles) {
            free(listEntry->data);
        }
        list_freeList(intra_day_candle_data->candles);
        intra_day_candle_data->candles = NULL;
    }
    free(intra_day_candle_data);
}

cJSON *intra_day_candle_data_convertToJSON(intra_day_candle_data_t *intra_day_candle_data) {
    cJSON *item = cJSON_CreateObject();

    // intra_day_candle_data->candles
    if(intra_day_candle_data->candles) {
    cJSON *candles = cJSON_AddArrayToObject(item, "candles");
    if(candles == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *candlesListEntry;
    list_ForEach(candlesListEntry, intra_day_candle_data->candles) {
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

intra_day_candle_data_t *intra_day_candle_data_parseFromJSON(cJSON *intra_day_candle_dataJSON){

    intra_day_candle_data_t *intra_day_candle_data_local_var = NULL;

    // define the local list for intra_day_candle_data->candles
    list_t *candlesList = NULL;

    // intra_day_candle_data->candles
    cJSON *candles = cJSON_GetObjectItemCaseSensitive(intra_day_candle_dataJSON, "candles");
    if (cJSON_IsNull(candles)) {
        candles = NULL;
    }
    if (candles) { 
    cJSON *candles_local = NULL;
    if(!cJSON_IsArray(candles)) {
        goto end;//primitive container
    }
    candlesList = list_createList();

    cJSON_ArrayForEach(candles_local, candles)
    {
    }
    }



    intra_day_candle_data_local_var = intra_day_candle_data_create_internal (
        candles ? candlesList : NULL
        );

    if (!intra_day_candle_data_local_var) {
        goto end;
    }

    return intra_day_candle_data_local_var;
end:
    if (candlesList) {
        list_freeList(candlesList);
        candlesList = NULL;
    }
    return NULL;

}
