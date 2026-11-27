#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "holiday_data.h"


char* holiday_data_holiday_type_ToString(upstox_client_holiday_data_HOLIDAYTYPE_e holiday_type) {
    char* holiday_typeArray[] =  { "NULL", "ALL", "SETTLEMENT_HOLIDAY", "TRADING_HOLIDAY", "SPECIAL_TIMING" };
    return holiday_typeArray[holiday_type];
}

upstox_client_holiday_data_HOLIDAYTYPE_e holiday_data_holiday_type_FromString(char* holiday_type){
    int stringToReturn = 0;
    char *holiday_typeArray[] =  { "NULL", "ALL", "SETTLEMENT_HOLIDAY", "TRADING_HOLIDAY", "SPECIAL_TIMING" };
    size_t sizeofArray = sizeof(holiday_typeArray) / sizeof(holiday_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(holiday_type, holiday_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static holiday_data_t *holiday_data_create_internal(
    char *date,
    char *description,
    upstox_client_holiday_data_HOLIDAYTYPE_e holiday_type,
    list_t *closed_exchanges,
    list_t *open_exchanges
    ) {
    holiday_data_t *holiday_data_local_var = malloc(sizeof(holiday_data_t));
    if (!holiday_data_local_var) {
        return NULL;
    }
    memset(holiday_data_local_var, 0, sizeof(holiday_data_t));
    holiday_data_local_var->_library_owned = 1;
    holiday_data_local_var->date = date;
    holiday_data_local_var->description = description;
    holiday_data_local_var->holiday_type = holiday_type;
    holiday_data_local_var->closed_exchanges = closed_exchanges;
    holiday_data_local_var->open_exchanges = open_exchanges;
    return holiday_data_local_var;
}

holiday_data_t *holiday_data_create(
    char *date,
    char *description,
    upstox_client_holiday_data_HOLIDAYTYPE_e holiday_type,
    list_t *closed_exchanges,
    list_t *open_exchanges
    ) {
    holiday_data_t *result = holiday_data_create_internal (
        date,
        description,
        holiday_type,
        closed_exchanges,
        open_exchanges
        );
    if (!result) {
    }
    return result;
}

void holiday_data_free(holiday_data_t *holiday_data) {
    if(NULL == holiday_data){
        return ;
    }
    if(holiday_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "holiday_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (holiday_data->date) {
        free(holiday_data->date);
        holiday_data->date = NULL;
    }
    if (holiday_data->description) {
        free(holiday_data->description);
        holiday_data->description = NULL;
    }
    if (holiday_data->closed_exchanges) {
        list_ForEach(listEntry, holiday_data->closed_exchanges) {
            free(listEntry->data);
        }
        list_freeList(holiday_data->closed_exchanges);
        holiday_data->closed_exchanges = NULL;
    }
    if (holiday_data->open_exchanges) {
        list_ForEach(listEntry, holiday_data->open_exchanges) {
            exchange_timing_data_free(listEntry->data);
        }
        list_freeList(holiday_data->open_exchanges);
        holiday_data->open_exchanges = NULL;
    }
    free(holiday_data);
}

cJSON *holiday_data_convertToJSON(holiday_data_t *holiday_data) {
    cJSON *item = cJSON_CreateObject();

    // holiday_data->date
    if(holiday_data->date) {
    if(cJSON_AddStringToObject(item, "date", holiday_data->date) == NULL) {
    goto fail; //Date-Time
    }
    }


    // holiday_data->description
    if(holiday_data->description) {
    if(cJSON_AddStringToObject(item, "description", holiday_data->description) == NULL) {
    goto fail; //String
    }
    }


    // holiday_data->holiday_type
    if(holiday_data->holiday_type != upstox_client_holiday_data_HOLIDAYTYPE_NULL) {
    if(cJSON_AddStringToObject(item, "holiday_type", holiday_data_holiday_type_ToString(holiday_data->holiday_type)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // holiday_data->closed_exchanges
    if(holiday_data->closed_exchanges) {
    cJSON *closed_exchanges = cJSON_AddArrayToObject(item, "closed_exchanges");
    if(closed_exchanges == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *closed_exchangesListEntry;
    list_ForEach(closed_exchangesListEntry, holiday_data->closed_exchanges) {
    if(cJSON_AddStringToObject(closed_exchanges, "", closed_exchangesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // holiday_data->open_exchanges
    if(holiday_data->open_exchanges) {
    cJSON *open_exchanges = cJSON_AddArrayToObject(item, "open_exchanges");
    if(open_exchanges == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *open_exchangesListEntry;
    if (holiday_data->open_exchanges) {
    list_ForEach(open_exchangesListEntry, holiday_data->open_exchanges) {
    cJSON *itemLocal = exchange_timing_data_convertToJSON(open_exchangesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(open_exchanges, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

holiday_data_t *holiday_data_parseFromJSON(cJSON *holiday_dataJSON){

    holiday_data_t *holiday_data_local_var = NULL;

    char *date_local_str = NULL;

    char *description_local_str = NULL;

    // define the local list for holiday_data->closed_exchanges
    list_t *closed_exchangesList = NULL;

    // define the local list for holiday_data->open_exchanges
    list_t *open_exchangesList = NULL;

    // holiday_data->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(holiday_dataJSON, "date");
    if (cJSON_IsNull(date)) {
        date = NULL;
    }
    if (date) { 
    if(!cJSON_IsString(date) && !cJSON_IsNull(date))
    {
    goto end; //DateTime
    }
    }

    // holiday_data->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(holiday_dataJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // holiday_data->holiday_type
    cJSON *holiday_type = cJSON_GetObjectItemCaseSensitive(holiday_dataJSON, "holiday_type");
    if (cJSON_IsNull(holiday_type)) {
        holiday_type = NULL;
    }
    upstox_client_holiday_data_HOLIDAYTYPE_e holiday_typeVariable;
    if (holiday_type) { 
    if(!cJSON_IsString(holiday_type))
    {
    goto end; //Enum
    }
    holiday_typeVariable = holiday_data_holiday_type_FromString(holiday_type->valuestring);
    }

    // holiday_data->closed_exchanges
    cJSON *closed_exchanges = cJSON_GetObjectItemCaseSensitive(holiday_dataJSON, "closed_exchanges");
    if (cJSON_IsNull(closed_exchanges)) {
        closed_exchanges = NULL;
    }
    if (closed_exchanges) { 
    cJSON *closed_exchanges_local = NULL;
    if(!cJSON_IsArray(closed_exchanges)) {
        goto end;//primitive container
    }
    closed_exchangesList = list_createList();

    cJSON_ArrayForEach(closed_exchanges_local, closed_exchanges)
    {
        if(!cJSON_IsString(closed_exchanges_local))
        {
            goto end;
        }
        list_addElement(closed_exchangesList , strdup(closed_exchanges_local->valuestring));
    }
    }

    // holiday_data->open_exchanges
    cJSON *open_exchanges = cJSON_GetObjectItemCaseSensitive(holiday_dataJSON, "open_exchanges");
    if (cJSON_IsNull(open_exchanges)) {
        open_exchanges = NULL;
    }
    if (open_exchanges) { 
    cJSON *open_exchanges_local_nonprimitive = NULL;
    if(!cJSON_IsArray(open_exchanges)){
        goto end; //nonprimitive container
    }

    open_exchangesList = list_createList();

    cJSON_ArrayForEach(open_exchanges_local_nonprimitive,open_exchanges )
    {
        if(!cJSON_IsObject(open_exchanges_local_nonprimitive)){
            goto end;
        }
        exchange_timing_data_t *open_exchangesItem = exchange_timing_data_parseFromJSON(open_exchanges_local_nonprimitive);

        list_addElement(open_exchangesList, open_exchangesItem);
    }
    }


    if (date && !cJSON_IsNull(date)) date_local_str = strdup(date->valuestring);
    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);

    holiday_data_local_var = holiday_data_create_internal (
        date_local_str,
        description_local_str,
        holiday_type ? holiday_typeVariable : upstox_client_holiday_data_HOLIDAYTYPE_NULL,
        closed_exchanges ? closed_exchangesList : NULL,
        open_exchanges ? open_exchangesList : NULL
        );

    if (!holiday_data_local_var) {
        goto end;
    }

    return holiday_data_local_var;
end:
    if (date_local_str) {
        free(date_local_str);
        date_local_str = NULL;
    }
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    if (closed_exchangesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, closed_exchangesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(closed_exchangesList);
        closed_exchangesList = NULL;
    }
    if (open_exchangesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, open_exchangesList) {
            exchange_timing_data_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(open_exchangesList);
        open_exchangesList = NULL;
    }
    return NULL;

}
