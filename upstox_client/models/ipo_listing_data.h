/*
 * ipo_listing_data.h
 *
 * 
 */

#ifndef _ipo_listing_data_H_
#define _ipo_listing_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ipo_listing_data_t ipo_listing_data_t;

#include "ipo_investor_type.h"

// Enum STATUS for ipo_listing_data

typedef enum  { upstox_client_ipo_listing_data_STATUS_NULL = 0, upstox_client_ipo_listing_data_STATUS_open, upstox_client_ipo_listing_data_STATUS_closed, upstox_client_ipo_listing_data_STATUS_listed, upstox_client_ipo_listing_data_STATUS_upcoming } upstox_client_ipo_listing_data_STATUS_e;

char* ipo_listing_data_status_ToString(upstox_client_ipo_listing_data_STATUS_e status);

upstox_client_ipo_listing_data_STATUS_e ipo_listing_data_status_FromString(char* status);

// Enum ISSUETYPE for ipo_listing_data

typedef enum  { upstox_client_ipo_listing_data_ISSUETYPE_NULL = 0, upstox_client_ipo_listing_data_ISSUETYPE_regular, upstox_client_ipo_listing_data_ISSUETYPE_sme } upstox_client_ipo_listing_data_ISSUETYPE_e;

char* ipo_listing_data_issue_type_ToString(upstox_client_ipo_listing_data_ISSUETYPE_e issue_type);

upstox_client_ipo_listing_data_ISSUETYPE_e ipo_listing_data_issue_type_FromString(char* issue_type);



typedef struct ipo_listing_data_t {
    char *id; // string
    char *symbol; // string
    char *name; // string
    upstox_client_ipo_listing_data_STATUS_e status; //enum
    char *isin; // string
    upstox_client_ipo_listing_data_ISSUETYPE_e issue_type; //enum
    double *issue_size; //numeric
    char *industry; // string
    double *minimum_price; //numeric
    double *maximum_price; //numeric
    char *bidding_start_date; // string
    char *bidding_end_date; // string
    char *total_subscription; // string
    list_t *investors; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} ipo_listing_data_t;

ipo_listing_data_t *ipo_listing_data_create(
    char *id,
    char *symbol,
    char *name,
    upstox_client_ipo_listing_data_STATUS_e status,
    char *isin,
    upstox_client_ipo_listing_data_ISSUETYPE_e issue_type,
    double *issue_size,
    char *industry,
    double *minimum_price,
    double *maximum_price,
    char *bidding_start_date,
    char *bidding_end_date,
    char *total_subscription,
    list_t *investors
);

void ipo_listing_data_free(ipo_listing_data_t *ipo_listing_data);

ipo_listing_data_t *ipo_listing_data_parseFromJSON(cJSON *ipo_listing_dataJSON);

cJSON *ipo_listing_data_convertToJSON(ipo_listing_data_t *ipo_listing_data);

#endif /* _ipo_listing_data_H_ */

