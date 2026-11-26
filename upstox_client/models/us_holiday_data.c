#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "us_holiday_data.h"


char* us_holiday_data_holiday_type_ToString(upstox_client_us_holiday_data_HOLIDAYTYPE_e holiday_type) {
    char* holiday_typeArray[] =  { "NULL", "ALL", "SETTLEMENT_HOLIDAY", "TRADING_HOLIDAY", "SPECIAL_TIMING" };
    return holiday_typeArray[holiday_type];
}

upstox_client_us_holiday_data_HOLIDAYTYPE_e us_holiday_data_holiday_type_FromString(char* holiday_type){
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

static us_holiday_data_t *us_holiday_data_create_internal(
    char *date,
    upstox_client_us_holiday_data_HOLIDAYTYPE_e holiday_type
    ) {
    us_holiday_data_t *us_holiday_data_local_var = malloc(sizeof(us_holiday_data_t));
    if (!us_holiday_data_local_var) {
        return NULL;
    }
    memset(us_holiday_data_local_var, 0, sizeof(us_holiday_data_t));
    us_holiday_data_local_var->_library_owned = 1;
    us_holiday_data_local_var->date = date;
    us_holiday_data_local_var->holiday_type = holiday_type;
    return us_holiday_data_local_var;
}

us_holiday_data_t *us_holiday_data_create(
    char *date,
    upstox_client_us_holiday_data_HOLIDAYTYPE_e holiday_type
    ) {
    us_holiday_data_t *result = us_holiday_data_create_internal (
        date,
        holiday_type
        );
    if (!result) {
    }
    return result;
}

void us_holiday_data_free(us_holiday_data_t *us_holiday_data) {
    if(NULL == us_holiday_data){
        return ;
    }
    if(us_holiday_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "us_holiday_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (us_holiday_data->date) {
        free(us_holiday_data->date);
        us_holiday_data->date = NULL;
    }
    free(us_holiday_data);
}

cJSON *us_holiday_data_convertToJSON(us_holiday_data_t *us_holiday_data) {
    cJSON *item = cJSON_CreateObject();

    // us_holiday_data->date
    if(us_holiday_data->date) {
    if(cJSON_AddStringToObject(item, "date", us_holiday_data->date) == NULL) {
    goto fail; //String
    }
    }


    // us_holiday_data->holiday_type
    if(us_holiday_data->holiday_type != upstox_client_us_holiday_data_HOLIDAYTYPE_NULL) {
    if(cJSON_AddStringToObject(item, "holiday_type", us_holiday_data_holiday_type_ToString(us_holiday_data->holiday_type)) == NULL)
    {
    goto fail; //Enum
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

us_holiday_data_t *us_holiday_data_parseFromJSON(cJSON *us_holiday_dataJSON){

    us_holiday_data_t *us_holiday_data_local_var = NULL;

    char *date_local_str = NULL;

    // us_holiday_data->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(us_holiday_dataJSON, "date");
    if (cJSON_IsNull(date)) {
        date = NULL;
    }
    if (date) { 
    if(!cJSON_IsString(date) && !cJSON_IsNull(date))
    {
    goto end; //String
    }
    }

    // us_holiday_data->holiday_type
    cJSON *holiday_type = cJSON_GetObjectItemCaseSensitive(us_holiday_dataJSON, "holiday_type");
    if (cJSON_IsNull(holiday_type)) {
        holiday_type = NULL;
    }
    upstox_client_us_holiday_data_HOLIDAYTYPE_e holiday_typeVariable;
    if (holiday_type) { 
    if(!cJSON_IsString(holiday_type))
    {
    goto end; //Enum
    }
    holiday_typeVariable = us_holiday_data_holiday_type_FromString(holiday_type->valuestring);
    }


    if (date && !cJSON_IsNull(date)) date_local_str = strdup(date->valuestring);

    us_holiday_data_local_var = us_holiday_data_create_internal (
        date_local_str,
        holiday_type ? holiday_typeVariable : upstox_client_us_holiday_data_HOLIDAYTYPE_NULL
        );

    if (!us_holiday_data_local_var) {
        goto end;
    }

    return us_holiday_data_local_var;
end:
    if (date_local_str) {
        free(date_local_str);
        date_local_str = NULL;
    }
    return NULL;

}
