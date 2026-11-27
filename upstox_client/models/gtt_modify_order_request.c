#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gtt_modify_order_request.h"


char* gtt_modify_order_request_type_ToString(upstox_client_gtt_modify_order_request_TYPE_e type) {
    char* typeArray[] =  { "NULL", "SINGLE", "MULTIPLE" };
    return typeArray[type];
}

upstox_client_gtt_modify_order_request_TYPE_e gtt_modify_order_request_type_FromString(char* type){
    int stringToReturn = 0;
    char *typeArray[] =  { "NULL", "SINGLE", "MULTIPLE" };
    size_t sizeofArray = sizeof(typeArray) / sizeof(typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(type, typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static gtt_modify_order_request_t *gtt_modify_order_request_create_internal(
    upstox_client_gtt_modify_order_request_TYPE_e type,
    int *quantity,
    list_t *rules,
    char *gtt_order_id
    ) {
    gtt_modify_order_request_t *gtt_modify_order_request_local_var = malloc(sizeof(gtt_modify_order_request_t));
    if (!gtt_modify_order_request_local_var) {
        return NULL;
    }
    memset(gtt_modify_order_request_local_var, 0, sizeof(gtt_modify_order_request_t));
    gtt_modify_order_request_local_var->_library_owned = 1;
    gtt_modify_order_request_local_var->type = type;
    gtt_modify_order_request_local_var->quantity = quantity;
    gtt_modify_order_request_local_var->rules = rules;
    gtt_modify_order_request_local_var->gtt_order_id = gtt_order_id;
    return gtt_modify_order_request_local_var;
}

gtt_modify_order_request_t *gtt_modify_order_request_create(
    upstox_client_gtt_modify_order_request_TYPE_e type,
    int *quantity,
    list_t *rules,
    char *gtt_order_id
    ) {
    int *quantity_copy = NULL;
    if (quantity) {
        quantity_copy = malloc(sizeof(int));
        if (quantity_copy) *quantity_copy = *quantity;
    }
    gtt_modify_order_request_t *result = gtt_modify_order_request_create_internal (
        type,
        quantity_copy,
        rules,
        gtt_order_id
        );
    if (!result) {
        free(quantity_copy);
    }
    return result;
}

void gtt_modify_order_request_free(gtt_modify_order_request_t *gtt_modify_order_request) {
    if(NULL == gtt_modify_order_request){
        return ;
    }
    if(gtt_modify_order_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gtt_modify_order_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gtt_modify_order_request->quantity) {
        free(gtt_modify_order_request->quantity);
        gtt_modify_order_request->quantity = NULL;
    }
    if (gtt_modify_order_request->rules) {
        list_ForEach(listEntry, gtt_modify_order_request->rules) {
            gtt_rule_free(listEntry->data);
        }
        list_freeList(gtt_modify_order_request->rules);
        gtt_modify_order_request->rules = NULL;
    }
    if (gtt_modify_order_request->gtt_order_id) {
        free(gtt_modify_order_request->gtt_order_id);
        gtt_modify_order_request->gtt_order_id = NULL;
    }
    free(gtt_modify_order_request);
}

cJSON *gtt_modify_order_request_convertToJSON(gtt_modify_order_request_t *gtt_modify_order_request) {
    cJSON *item = cJSON_CreateObject();

    // gtt_modify_order_request->type
    if (upstox_client_gtt_modify_order_request_TYPE_NULL == gtt_modify_order_request->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", gtt_modify_order_request_type_ToString(gtt_modify_order_request->type)) == NULL)
    {
    goto fail; //Enum
    }


    // gtt_modify_order_request->quantity
    if (!gtt_modify_order_request->quantity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "quantity", *gtt_modify_order_request->quantity) == NULL) {
    goto fail; //Numeric
    }


    // gtt_modify_order_request->rules
    if (!gtt_modify_order_request->rules) {
        goto fail;
    }
    cJSON *rules = cJSON_AddArrayToObject(item, "rules");
    if(rules == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *rulesListEntry;
    if (gtt_modify_order_request->rules) {
    list_ForEach(rulesListEntry, gtt_modify_order_request->rules) {
    cJSON *itemLocal = gtt_rule_convertToJSON(rulesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(rules, itemLocal);
    }
    }


    // gtt_modify_order_request->gtt_order_id
    if (!gtt_modify_order_request->gtt_order_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gtt_order_id", gtt_modify_order_request->gtt_order_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gtt_modify_order_request_t *gtt_modify_order_request_parseFromJSON(cJSON *gtt_modify_order_requestJSON){

    gtt_modify_order_request_t *gtt_modify_order_request_local_var = NULL;

    // define the local variable for gtt_modify_order_request->quantity
    int *quantity_local_var = NULL;

    // define the local list for gtt_modify_order_request->rules
    list_t *rulesList = NULL;

    char *gtt_order_id_local_str = NULL;

    // gtt_modify_order_request->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(gtt_modify_order_requestJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    upstox_client_gtt_modify_order_request_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = gtt_modify_order_request_type_FromString(type->valuestring);

    // gtt_modify_order_request->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(gtt_modify_order_requestJSON, "quantity");
    if (cJSON_IsNull(quantity)) {
        quantity = NULL;
    }
    if (!quantity) {
        goto end;
    }

    
    if(!cJSON_IsNumber(quantity))
    {
    goto end; //Numeric
    }
    quantity_local_var = malloc(sizeof(int));
    if(!quantity_local_var)
    {
        goto end;
    }
    *quantity_local_var = quantity->valuedouble;

    // gtt_modify_order_request->rules
    cJSON *rules = cJSON_GetObjectItemCaseSensitive(gtt_modify_order_requestJSON, "rules");
    if (cJSON_IsNull(rules)) {
        rules = NULL;
    }
    if (!rules) {
        goto end;
    }

    
    cJSON *rules_local_nonprimitive = NULL;
    if(!cJSON_IsArray(rules)){
        goto end; //nonprimitive container
    }

    rulesList = list_createList();

    cJSON_ArrayForEach(rules_local_nonprimitive,rules )
    {
        if(!cJSON_IsObject(rules_local_nonprimitive)){
            goto end;
        }
        gtt_rule_t *rulesItem = gtt_rule_parseFromJSON(rules_local_nonprimitive);

        list_addElement(rulesList, rulesItem);
    }

    // gtt_modify_order_request->gtt_order_id
    cJSON *gtt_order_id = cJSON_GetObjectItemCaseSensitive(gtt_modify_order_requestJSON, "gtt_order_id");
    if (cJSON_IsNull(gtt_order_id)) {
        gtt_order_id = NULL;
    }
    if (!gtt_order_id) {
        goto end;
    }

    
    if(!cJSON_IsString(gtt_order_id))
    {
    goto end; //String
    }


    if (gtt_order_id && !cJSON_IsNull(gtt_order_id)) gtt_order_id_local_str = strdup(gtt_order_id->valuestring);

    gtt_modify_order_request_local_var = gtt_modify_order_request_create_internal (
        typeVariable,
        quantity_local_var,
        rulesList,
        gtt_order_id_local_str
        );

    if (!gtt_modify_order_request_local_var) {
        goto end;
    }

    return gtt_modify_order_request_local_var;
end:
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    if (rulesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, rulesList) {
            gtt_rule_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(rulesList);
        rulesList = NULL;
    }
    if (gtt_order_id_local_str) {
        free(gtt_order_id_local_str);
        gtt_order_id_local_str = NULL;
    }
    return NULL;

}
