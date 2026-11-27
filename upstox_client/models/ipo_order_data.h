/*
 * ipo_order_data.h
 *
 * 
 */

#ifndef _ipo_order_data_H_
#define _ipo_order_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ipo_order_data_t ipo_order_data_t;

#include "ipo_order_bid.h"

// Enum ISSUETYPE for ipo_order_data

typedef enum  { upstox_client_ipo_order_data_ISSUETYPE_NULL = 0, upstox_client_ipo_order_data_ISSUETYPE_regular, upstox_client_ipo_order_data_ISSUETYPE_sme } upstox_client_ipo_order_data_ISSUETYPE_e;

char* ipo_order_data_issue_type_ToString(upstox_client_ipo_order_data_ISSUETYPE_e issue_type);

upstox_client_ipo_order_data_ISSUETYPE_e ipo_order_data_issue_type_FromString(char* issue_type);



typedef struct ipo_order_data_t {
    char *id; // string
    char *symbol; // string
    char *exchange; // string
    char *request_id; // string
    char *order_id; // string
    char *status; // string
    char *order_status; // string
    char *payment_status; // string
    char *category; // string
    upstox_client_ipo_order_data_ISSUETYPE_e issue_type; //enum
    char *reason; // string
    char *upi; // string
    char *upi_amount_blocked; // string
    char *nse_submitted_date; // string
    char *bse_submitted_date; // string
    char *mandate_approved_date; // string
    char *rejection_date; // string
    char *mandate_rejection_date; // string
    char *cancel_requested_date; // string
    char *cancel_accepted_date; // string
    int *units_allotted; //numeric
    list_t *bids; //nonprimitive container
    char *created_at; // string
    char *last_updated_at; // string

    int _library_owned; // Is the library responsible for freeing this object?
} ipo_order_data_t;

ipo_order_data_t *ipo_order_data_create(
    char *id,
    char *symbol,
    char *exchange,
    char *request_id,
    char *order_id,
    char *status,
    char *order_status,
    char *payment_status,
    char *category,
    upstox_client_ipo_order_data_ISSUETYPE_e issue_type,
    char *reason,
    char *upi,
    char *upi_amount_blocked,
    char *nse_submitted_date,
    char *bse_submitted_date,
    char *mandate_approved_date,
    char *rejection_date,
    char *mandate_rejection_date,
    char *cancel_requested_date,
    char *cancel_accepted_date,
    int *units_allotted,
    list_t *bids,
    char *created_at,
    char *last_updated_at
);

void ipo_order_data_free(ipo_order_data_t *ipo_order_data);

ipo_order_data_t *ipo_order_data_parseFromJSON(cJSON *ipo_order_dataJSON);

cJSON *ipo_order_data_convertToJSON(ipo_order_data_t *ipo_order_data);

#endif /* _ipo_order_data_H_ */

