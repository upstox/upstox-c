#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipo_investor_type.h"


char* ipo_investor_type_category_ToString(upstox_client_ipo_investor_type_CATEGORY_e category) {
    char* categoryArray[] =  { "NULL", "IND", "HNI" };
    return categoryArray[category];
}

upstox_client_ipo_investor_type_CATEGORY_e ipo_investor_type_category_FromString(char* category){
    int stringToReturn = 0;
    char *categoryArray[] =  { "NULL", "IND", "HNI" };
    size_t sizeofArray = sizeof(categoryArray) / sizeof(categoryArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(category, categoryArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static ipo_investor_type_t *ipo_investor_type_create_internal(
    upstox_client_ipo_investor_type_CATEGORY_e category,
    char *description
    ) {
    ipo_investor_type_t *ipo_investor_type_local_var = malloc(sizeof(ipo_investor_type_t));
    if (!ipo_investor_type_local_var) {
        return NULL;
    }
    memset(ipo_investor_type_local_var, 0, sizeof(ipo_investor_type_t));
    ipo_investor_type_local_var->_library_owned = 1;
    ipo_investor_type_local_var->category = category;
    ipo_investor_type_local_var->description = description;
    return ipo_investor_type_local_var;
}

ipo_investor_type_t *ipo_investor_type_create(
    upstox_client_ipo_investor_type_CATEGORY_e category,
    char *description
    ) {
    ipo_investor_type_t *result = ipo_investor_type_create_internal (
        category,
        description
        );
    if (!result) {
    }
    return result;
}

void ipo_investor_type_free(ipo_investor_type_t *ipo_investor_type) {
    if(NULL == ipo_investor_type){
        return ;
    }
    if(ipo_investor_type->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ipo_investor_type_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ipo_investor_type->description) {
        free(ipo_investor_type->description);
        ipo_investor_type->description = NULL;
    }
    free(ipo_investor_type);
}

cJSON *ipo_investor_type_convertToJSON(ipo_investor_type_t *ipo_investor_type) {
    cJSON *item = cJSON_CreateObject();

    // ipo_investor_type->category
    if(ipo_investor_type->category != upstox_client_ipo_investor_type_CATEGORY_NULL) {
    if(cJSON_AddStringToObject(item, "category", ipo_investor_type_category_ToString(ipo_investor_type->category)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // ipo_investor_type->description
    if(ipo_investor_type->description) {
    if(cJSON_AddStringToObject(item, "description", ipo_investor_type->description) == NULL) {
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

ipo_investor_type_t *ipo_investor_type_parseFromJSON(cJSON *ipo_investor_typeJSON){

    ipo_investor_type_t *ipo_investor_type_local_var = NULL;

    char *description_local_str = NULL;

    // ipo_investor_type->category
    cJSON *category = cJSON_GetObjectItemCaseSensitive(ipo_investor_typeJSON, "category");
    if (cJSON_IsNull(category)) {
        category = NULL;
    }
    upstox_client_ipo_investor_type_CATEGORY_e categoryVariable;
    if (category) { 
    if(!cJSON_IsString(category))
    {
    goto end; //Enum
    }
    categoryVariable = ipo_investor_type_category_FromString(category->valuestring);
    }

    // ipo_investor_type->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(ipo_investor_typeJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }


    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);

    ipo_investor_type_local_var = ipo_investor_type_create_internal (
        category ? categoryVariable : upstox_client_ipo_investor_type_CATEGORY_NULL,
        description_local_str
        );

    if (!ipo_investor_type_local_var) {
        goto end;
    }

    return ipo_investor_type_local_var;
end:
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    return NULL;

}
