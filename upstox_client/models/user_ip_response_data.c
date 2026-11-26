#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "user_ip_response_data.h"



static user_ip_response_data_t *user_ip_response_data_create_internal(
    char *primary_ip,
    char *secondary_ip,
    char *primary_ip_updated_at,
    char *secondary_ip_updated_at,
    list_t *primary_ip_family_members,
    list_t *secondary_ip_family_members,
    int *access_tokens_invalidated
    ) {
    user_ip_response_data_t *user_ip_response_data_local_var = malloc(sizeof(user_ip_response_data_t));
    if (!user_ip_response_data_local_var) {
        return NULL;
    }
    memset(user_ip_response_data_local_var, 0, sizeof(user_ip_response_data_t));
    user_ip_response_data_local_var->_library_owned = 1;
    user_ip_response_data_local_var->primary_ip = primary_ip;
    user_ip_response_data_local_var->secondary_ip = secondary_ip;
    user_ip_response_data_local_var->primary_ip_updated_at = primary_ip_updated_at;
    user_ip_response_data_local_var->secondary_ip_updated_at = secondary_ip_updated_at;
    user_ip_response_data_local_var->primary_ip_family_members = primary_ip_family_members;
    user_ip_response_data_local_var->secondary_ip_family_members = secondary_ip_family_members;
    user_ip_response_data_local_var->access_tokens_invalidated = access_tokens_invalidated;
    return user_ip_response_data_local_var;
}

user_ip_response_data_t *user_ip_response_data_create(
    char *primary_ip,
    char *secondary_ip,
    char *primary_ip_updated_at,
    char *secondary_ip_updated_at,
    list_t *primary_ip_family_members,
    list_t *secondary_ip_family_members,
    int *access_tokens_invalidated
    ) {
    int *access_tokens_invalidated_copy = NULL;
    if (access_tokens_invalidated) {
        access_tokens_invalidated_copy = malloc(sizeof(int));
        if (access_tokens_invalidated_copy) *access_tokens_invalidated_copy = *access_tokens_invalidated;
    }
    user_ip_response_data_t *result = user_ip_response_data_create_internal (
        primary_ip,
        secondary_ip,
        primary_ip_updated_at,
        secondary_ip_updated_at,
        primary_ip_family_members,
        secondary_ip_family_members,
        access_tokens_invalidated_copy
        );
    if (!result) {
        free(access_tokens_invalidated_copy);
    }
    return result;
}

void user_ip_response_data_free(user_ip_response_data_t *user_ip_response_data) {
    if(NULL == user_ip_response_data){
        return ;
    }
    if(user_ip_response_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "user_ip_response_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (user_ip_response_data->primary_ip) {
        free(user_ip_response_data->primary_ip);
        user_ip_response_data->primary_ip = NULL;
    }
    if (user_ip_response_data->secondary_ip) {
        free(user_ip_response_data->secondary_ip);
        user_ip_response_data->secondary_ip = NULL;
    }
    if (user_ip_response_data->primary_ip_updated_at) {
        free(user_ip_response_data->primary_ip_updated_at);
        user_ip_response_data->primary_ip_updated_at = NULL;
    }
    if (user_ip_response_data->secondary_ip_updated_at) {
        free(user_ip_response_data->secondary_ip_updated_at);
        user_ip_response_data->secondary_ip_updated_at = NULL;
    }
    if (user_ip_response_data->primary_ip_family_members) {
        list_ForEach(listEntry, user_ip_response_data->primary_ip_family_members) {
            family_member_data_free(listEntry->data);
        }
        list_freeList(user_ip_response_data->primary_ip_family_members);
        user_ip_response_data->primary_ip_family_members = NULL;
    }
    if (user_ip_response_data->secondary_ip_family_members) {
        list_ForEach(listEntry, user_ip_response_data->secondary_ip_family_members) {
            family_member_data_free(listEntry->data);
        }
        list_freeList(user_ip_response_data->secondary_ip_family_members);
        user_ip_response_data->secondary_ip_family_members = NULL;
    }
    if (user_ip_response_data->access_tokens_invalidated) {
        free(user_ip_response_data->access_tokens_invalidated);
        user_ip_response_data->access_tokens_invalidated = NULL;
    }
    free(user_ip_response_data);
}

cJSON *user_ip_response_data_convertToJSON(user_ip_response_data_t *user_ip_response_data) {
    cJSON *item = cJSON_CreateObject();

    // user_ip_response_data->primary_ip
    if(user_ip_response_data->primary_ip) {
    if(cJSON_AddStringToObject(item, "primary_ip", user_ip_response_data->primary_ip) == NULL) {
    goto fail; //String
    }
    }


    // user_ip_response_data->secondary_ip
    if(user_ip_response_data->secondary_ip) {
    if(cJSON_AddStringToObject(item, "secondary_ip", user_ip_response_data->secondary_ip) == NULL) {
    goto fail; //String
    }
    }


    // user_ip_response_data->primary_ip_updated_at
    if(user_ip_response_data->primary_ip_updated_at) {
    if(cJSON_AddStringToObject(item, "primary_ip_updated_at", user_ip_response_data->primary_ip_updated_at) == NULL) {
    goto fail; //String
    }
    }


    // user_ip_response_data->secondary_ip_updated_at
    if(user_ip_response_data->secondary_ip_updated_at) {
    if(cJSON_AddStringToObject(item, "secondary_ip_updated_at", user_ip_response_data->secondary_ip_updated_at) == NULL) {
    goto fail; //String
    }
    }


    // user_ip_response_data->primary_ip_family_members
    if(user_ip_response_data->primary_ip_family_members) {
    cJSON *primary_ip_family_members = cJSON_AddArrayToObject(item, "primary_ip_family_members");
    if(primary_ip_family_members == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *primary_ip_family_membersListEntry;
    if (user_ip_response_data->primary_ip_family_members) {
    list_ForEach(primary_ip_family_membersListEntry, user_ip_response_data->primary_ip_family_members) {
    cJSON *itemLocal = family_member_data_convertToJSON(primary_ip_family_membersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(primary_ip_family_members, itemLocal);
    }
    }
    }


    // user_ip_response_data->secondary_ip_family_members
    if(user_ip_response_data->secondary_ip_family_members) {
    cJSON *secondary_ip_family_members = cJSON_AddArrayToObject(item, "secondary_ip_family_members");
    if(secondary_ip_family_members == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *secondary_ip_family_membersListEntry;
    if (user_ip_response_data->secondary_ip_family_members) {
    list_ForEach(secondary_ip_family_membersListEntry, user_ip_response_data->secondary_ip_family_members) {
    cJSON *itemLocal = family_member_data_convertToJSON(secondary_ip_family_membersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(secondary_ip_family_members, itemLocal);
    }
    }
    }


    // user_ip_response_data->access_tokens_invalidated
    if(user_ip_response_data->access_tokens_invalidated) {
    if(cJSON_AddBoolToObject(item, "access_tokens_invalidated", *user_ip_response_data->access_tokens_invalidated) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

user_ip_response_data_t *user_ip_response_data_parseFromJSON(cJSON *user_ip_response_dataJSON){

    user_ip_response_data_t *user_ip_response_data_local_var = NULL;

    char *primary_ip_local_str = NULL;

    char *secondary_ip_local_str = NULL;

    char *primary_ip_updated_at_local_str = NULL;

    char *secondary_ip_updated_at_local_str = NULL;

    // define the local list for user_ip_response_data->primary_ip_family_members
    list_t *primary_ip_family_membersList = NULL;

    // define the local list for user_ip_response_data->secondary_ip_family_members
    list_t *secondary_ip_family_membersList = NULL;

    // define the local variable for user_ip_response_data->access_tokens_invalidated
    int *access_tokens_invalidated_local_var = NULL;

    // user_ip_response_data->primary_ip
    cJSON *primary_ip = cJSON_GetObjectItemCaseSensitive(user_ip_response_dataJSON, "primary_ip");
    if (cJSON_IsNull(primary_ip)) {
        primary_ip = NULL;
    }
    if (primary_ip) { 
    if(!cJSON_IsString(primary_ip) && !cJSON_IsNull(primary_ip))
    {
    goto end; //String
    }
    }

    // user_ip_response_data->secondary_ip
    cJSON *secondary_ip = cJSON_GetObjectItemCaseSensitive(user_ip_response_dataJSON, "secondary_ip");
    if (cJSON_IsNull(secondary_ip)) {
        secondary_ip = NULL;
    }
    if (secondary_ip) { 
    if(!cJSON_IsString(secondary_ip) && !cJSON_IsNull(secondary_ip))
    {
    goto end; //String
    }
    }

    // user_ip_response_data->primary_ip_updated_at
    cJSON *primary_ip_updated_at = cJSON_GetObjectItemCaseSensitive(user_ip_response_dataJSON, "primary_ip_updated_at");
    if (cJSON_IsNull(primary_ip_updated_at)) {
        primary_ip_updated_at = NULL;
    }
    if (primary_ip_updated_at) { 
    if(!cJSON_IsString(primary_ip_updated_at) && !cJSON_IsNull(primary_ip_updated_at))
    {
    goto end; //String
    }
    }

    // user_ip_response_data->secondary_ip_updated_at
    cJSON *secondary_ip_updated_at = cJSON_GetObjectItemCaseSensitive(user_ip_response_dataJSON, "secondary_ip_updated_at");
    if (cJSON_IsNull(secondary_ip_updated_at)) {
        secondary_ip_updated_at = NULL;
    }
    if (secondary_ip_updated_at) { 
    if(!cJSON_IsString(secondary_ip_updated_at) && !cJSON_IsNull(secondary_ip_updated_at))
    {
    goto end; //String
    }
    }

    // user_ip_response_data->primary_ip_family_members
    cJSON *primary_ip_family_members = cJSON_GetObjectItemCaseSensitive(user_ip_response_dataJSON, "primary_ip_family_members");
    if (cJSON_IsNull(primary_ip_family_members)) {
        primary_ip_family_members = NULL;
    }
    if (primary_ip_family_members) { 
    cJSON *primary_ip_family_members_local_nonprimitive = NULL;
    if(!cJSON_IsArray(primary_ip_family_members)){
        goto end; //nonprimitive container
    }

    primary_ip_family_membersList = list_createList();

    cJSON_ArrayForEach(primary_ip_family_members_local_nonprimitive,primary_ip_family_members )
    {
        if(!cJSON_IsObject(primary_ip_family_members_local_nonprimitive)){
            goto end;
        }
        family_member_data_t *primary_ip_family_membersItem = family_member_data_parseFromJSON(primary_ip_family_members_local_nonprimitive);

        list_addElement(primary_ip_family_membersList, primary_ip_family_membersItem);
    }
    }

    // user_ip_response_data->secondary_ip_family_members
    cJSON *secondary_ip_family_members = cJSON_GetObjectItemCaseSensitive(user_ip_response_dataJSON, "secondary_ip_family_members");
    if (cJSON_IsNull(secondary_ip_family_members)) {
        secondary_ip_family_members = NULL;
    }
    if (secondary_ip_family_members) { 
    cJSON *secondary_ip_family_members_local_nonprimitive = NULL;
    if(!cJSON_IsArray(secondary_ip_family_members)){
        goto end; //nonprimitive container
    }

    secondary_ip_family_membersList = list_createList();

    cJSON_ArrayForEach(secondary_ip_family_members_local_nonprimitive,secondary_ip_family_members )
    {
        if(!cJSON_IsObject(secondary_ip_family_members_local_nonprimitive)){
            goto end;
        }
        family_member_data_t *secondary_ip_family_membersItem = family_member_data_parseFromJSON(secondary_ip_family_members_local_nonprimitive);

        list_addElement(secondary_ip_family_membersList, secondary_ip_family_membersItem);
    }
    }

    // user_ip_response_data->access_tokens_invalidated
    cJSON *access_tokens_invalidated = cJSON_GetObjectItemCaseSensitive(user_ip_response_dataJSON, "access_tokens_invalidated");
    if (cJSON_IsNull(access_tokens_invalidated)) {
        access_tokens_invalidated = NULL;
    }
    if (access_tokens_invalidated) { 
    if(!cJSON_IsBool(access_tokens_invalidated))
    {
    goto end; //Bool
    }
    access_tokens_invalidated_local_var = malloc(sizeof(int));
    if(!access_tokens_invalidated_local_var)
    {
        goto end;
    }
    *access_tokens_invalidated_local_var = access_tokens_invalidated->valueint;
    }


    if (primary_ip && !cJSON_IsNull(primary_ip)) primary_ip_local_str = strdup(primary_ip->valuestring);
    if (secondary_ip && !cJSON_IsNull(secondary_ip)) secondary_ip_local_str = strdup(secondary_ip->valuestring);
    if (primary_ip_updated_at && !cJSON_IsNull(primary_ip_updated_at)) primary_ip_updated_at_local_str = strdup(primary_ip_updated_at->valuestring);
    if (secondary_ip_updated_at && !cJSON_IsNull(secondary_ip_updated_at)) secondary_ip_updated_at_local_str = strdup(secondary_ip_updated_at->valuestring);

    user_ip_response_data_local_var = user_ip_response_data_create_internal (
        primary_ip_local_str,
        secondary_ip_local_str,
        primary_ip_updated_at_local_str,
        secondary_ip_updated_at_local_str,
        primary_ip_family_members ? primary_ip_family_membersList : NULL,
        secondary_ip_family_members ? secondary_ip_family_membersList : NULL,
        access_tokens_invalidated_local_var
        );

    if (!user_ip_response_data_local_var) {
        goto end;
    }

    return user_ip_response_data_local_var;
end:
    if (primary_ip_local_str) {
        free(primary_ip_local_str);
        primary_ip_local_str = NULL;
    }
    if (secondary_ip_local_str) {
        free(secondary_ip_local_str);
        secondary_ip_local_str = NULL;
    }
    if (primary_ip_updated_at_local_str) {
        free(primary_ip_updated_at_local_str);
        primary_ip_updated_at_local_str = NULL;
    }
    if (secondary_ip_updated_at_local_str) {
        free(secondary_ip_updated_at_local_str);
        secondary_ip_updated_at_local_str = NULL;
    }
    if (primary_ip_family_membersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, primary_ip_family_membersList) {
            family_member_data_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(primary_ip_family_membersList);
        primary_ip_family_membersList = NULL;
    }
    if (secondary_ip_family_membersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, secondary_ip_family_membersList) {
            family_member_data_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(secondary_ip_family_membersList);
        secondary_ip_family_membersList = NULL;
    }
    if (access_tokens_invalidated_local_var) {
        free(access_tokens_invalidated_local_var);
        access_tokens_invalidated_local_var = NULL;
    }
    return NULL;

}
