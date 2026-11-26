#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "depth_map.h"



static depth_map_t *depth_map_create_internal(
    list_t *buy,
    list_t *sell
    ) {
    depth_map_t *depth_map_local_var = malloc(sizeof(depth_map_t));
    if (!depth_map_local_var) {
        return NULL;
    }
    memset(depth_map_local_var, 0, sizeof(depth_map_t));
    depth_map_local_var->_library_owned = 1;
    depth_map_local_var->buy = buy;
    depth_map_local_var->sell = sell;
    return depth_map_local_var;
}

depth_map_t *depth_map_create(
    list_t *buy,
    list_t *sell
    ) {
    depth_map_t *result = depth_map_create_internal (
        buy,
        sell
        );
    if (!result) {
    }
    return result;
}

void depth_map_free(depth_map_t *depth_map) {
    if(NULL == depth_map){
        return ;
    }
    if(depth_map->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "depth_map_free");
        return ;
    }
    listEntry_t *listEntry;
    if (depth_map->buy) {
        list_ForEach(listEntry, depth_map->buy) {
            depth_free(listEntry->data);
        }
        list_freeList(depth_map->buy);
        depth_map->buy = NULL;
    }
    if (depth_map->sell) {
        list_ForEach(listEntry, depth_map->sell) {
            depth_free(listEntry->data);
        }
        list_freeList(depth_map->sell);
        depth_map->sell = NULL;
    }
    free(depth_map);
}

cJSON *depth_map_convertToJSON(depth_map_t *depth_map) {
    cJSON *item = cJSON_CreateObject();

    // depth_map->buy
    if(depth_map->buy) {
    cJSON *buy = cJSON_AddArrayToObject(item, "buy");
    if(buy == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *buyListEntry;
    if (depth_map->buy) {
    list_ForEach(buyListEntry, depth_map->buy) {
    cJSON *itemLocal = depth_convertToJSON(buyListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(buy, itemLocal);
    }
    }
    }


    // depth_map->sell
    if(depth_map->sell) {
    cJSON *sell = cJSON_AddArrayToObject(item, "sell");
    if(sell == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *sellListEntry;
    if (depth_map->sell) {
    list_ForEach(sellListEntry, depth_map->sell) {
    cJSON *itemLocal = depth_convertToJSON(sellListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(sell, itemLocal);
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

depth_map_t *depth_map_parseFromJSON(cJSON *depth_mapJSON){

    depth_map_t *depth_map_local_var = NULL;

    // define the local list for depth_map->buy
    list_t *buyList = NULL;

    // define the local list for depth_map->sell
    list_t *sellList = NULL;

    // depth_map->buy
    cJSON *buy = cJSON_GetObjectItemCaseSensitive(depth_mapJSON, "buy");
    if (cJSON_IsNull(buy)) {
        buy = NULL;
    }
    if (buy) { 
    cJSON *buy_local_nonprimitive = NULL;
    if(!cJSON_IsArray(buy)){
        goto end; //nonprimitive container
    }

    buyList = list_createList();

    cJSON_ArrayForEach(buy_local_nonprimitive,buy )
    {
        if(!cJSON_IsObject(buy_local_nonprimitive)){
            goto end;
        }
        depth_t *buyItem = depth_parseFromJSON(buy_local_nonprimitive);

        list_addElement(buyList, buyItem);
    }
    }

    // depth_map->sell
    cJSON *sell = cJSON_GetObjectItemCaseSensitive(depth_mapJSON, "sell");
    if (cJSON_IsNull(sell)) {
        sell = NULL;
    }
    if (sell) { 
    cJSON *sell_local_nonprimitive = NULL;
    if(!cJSON_IsArray(sell)){
        goto end; //nonprimitive container
    }

    sellList = list_createList();

    cJSON_ArrayForEach(sell_local_nonprimitive,sell )
    {
        if(!cJSON_IsObject(sell_local_nonprimitive)){
            goto end;
        }
        depth_t *sellItem = depth_parseFromJSON(sell_local_nonprimitive);

        list_addElement(sellList, sellItem);
    }
    }



    depth_map_local_var = depth_map_create_internal (
        buy ? buyList : NULL,
        sell ? sellList : NULL
        );

    if (!depth_map_local_var) {
        goto end;
    }

    return depth_map_local_var;
end:
    if (buyList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, buyList) {
            depth_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(buyList);
        buyList = NULL;
    }
    if (sellList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, sellList) {
            depth_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(sellList);
        sellList = NULL;
    }
    return NULL;

}
