/*
 * payment_history_data.h
 *
 * 
 */

#ifndef _payment_history_data_H_
#define _payment_history_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct payment_history_data_t payment_history_data_t;




typedef struct payment_history_data_t {
    double *amount; //numeric
    char *mode; // string
    char *status; // string
    char *reason; // string
    char *currency; // string
    char *eta; // string
    char *last_updated_at; // string
    char *bank_name; // string
    char *transaction_id; // string
    double *total_charges; //numeric
    char *charges_category; // string
    char *created_at; // string

    int _library_owned; // Is the library responsible for freeing this object?
} payment_history_data_t;

payment_history_data_t *payment_history_data_create(
    double *amount,
    char *mode,
    char *status,
    char *reason,
    char *currency,
    char *eta,
    char *last_updated_at,
    char *bank_name,
    char *transaction_id,
    double *total_charges,
    char *charges_category,
    char *created_at
);

void payment_history_data_free(payment_history_data_t *payment_history_data);

payment_history_data_t *payment_history_data_parseFromJSON(cJSON *payment_history_dataJSON);

cJSON *payment_history_data_convertToJSON(payment_history_data_t *payment_history_data);

#endif /* _payment_history_data_H_ */

