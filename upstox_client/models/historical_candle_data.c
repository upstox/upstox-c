#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "historical_candle_data.h"



static historical_candle_data_t *historical_candle_data_create_internal(
    list_t *candles
    ) {
    historical_candle_data_t *historical_candle_data_local_var = malloc(sizeof(historical_candle_data_t));
    if (!historical_candle_data_local_var) {
        return NULL;
    }
    memset(historical_candle_data_local_var, 0, sizeof(historical_candle_data_t));
    historical_candle_data_local_var->_library_owned = 1;
    historical_candle_data_local_var->candles = candles;
    return historical_candle_data_local_var;
}

historical_candle_data_t *historical_candle_data_create(
    list_t *candles
    ) {
    historical_candle_data_t *result = historical_candle_data_create_internal (
        candles
        );
    if (!result) {
    }
    return result;
}

void historical_candle_data_free(historical_candle_data_t *historical_candle_data) {
    if(NULL == historical_candle_data){
        return ;
    }
    if(historical_candle_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "historical_candle_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (historical_candle_data->candles) {
        list_ForEach(listEntry, historical_candle_data->candles) {
            free(listEntry->data);
        }
        list_freeList(historical_candle_data->candles);
        historical_candle_data->candles = NULL;
    }
    free(historical_candle_data);
}

cJSON *historical_candle_data_convertToJSON(historical_candle_data_t *historical_candle_data) {
    cJSON *item = cJSON_CreateObject();

    // historical_candle_data->candles
    if(historical_candle_data->candles) {
    cJSON *candles = cJSON_AddArrayToObject(item, "candles");
    if(candles == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *candlesListEntry;
    list_ForEach(candlesListEntry, historical_candle_data->candles) {
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

historical_candle_data_t *historical_candle_data_parseFromJSON(cJSON *historical_candle_dataJSON){

    historical_candle_data_t *historical_candle_data_local_var = NULL;

    // define the local list for historical_candle_data->candles
    list_t *candlesList = NULL;

    // historical_candle_data->candles
    cJSON *candles = cJSON_GetObjectItemCaseSensitive(historical_candle_dataJSON, "candles");
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



    historical_candle_data_local_var = historical_candle_data_create_internal (
        candles ? candlesList : NULL
        );

    if (!historical_candle_data_local_var) {
        goto end;
    }

    return historical_candle_data_local_var;
end:
    if (candlesList) {
        list_freeList(candlesList);
        candlesList = NULL;
    }
    return NULL;

}
