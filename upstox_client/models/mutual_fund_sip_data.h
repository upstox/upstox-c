/*
 * mutual_fund_sip_data.h
 *
 * 
 */

#ifndef _mutual_fund_sip_data_H_
#define _mutual_fund_sip_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct mutual_fund_sip_data_t mutual_fund_sip_data_t;




typedef struct mutual_fund_sip_data_t {
    char *fund; // string
    char *status; // string
    char *created; // string
    char *frequency; // string
    long *instalments; //numeric
    char *sip_id; // string
    char *sip_reg_number; // string
    char *instrument_key; // string
    char *dividend_type; // string
    char *transaction_type; // string
    char *next_instalment; // string
    double *instalment_amount; //numeric
    char *last_instalment; // string
    long *pending_instalments; //numeric
    long *instalment_day; //numeric
    long *completed_instalments; //numeric
    double *trigger_price; //numeric
    char *sip_type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} mutual_fund_sip_data_t;

mutual_fund_sip_data_t *mutual_fund_sip_data_create(
    char *fund,
    char *status,
    char *created,
    char *frequency,
    long *instalments,
    char *sip_id,
    char *sip_reg_number,
    char *instrument_key,
    char *dividend_type,
    char *transaction_type,
    char *next_instalment,
    double *instalment_amount,
    char *last_instalment,
    long *pending_instalments,
    long *instalment_day,
    long *completed_instalments,
    double *trigger_price,
    char *sip_type
);

void mutual_fund_sip_data_free(mutual_fund_sip_data_t *mutual_fund_sip_data);

mutual_fund_sip_data_t *mutual_fund_sip_data_parseFromJSON(cJSON *mutual_fund_sip_dataJSON);

cJSON *mutual_fund_sip_data_convertToJSON(mutual_fund_sip_data_t *mutual_fund_sip_data);

#endif /* _mutual_fund_sip_data_H_ */

