

#include <stdlib.h>
#include "transactions.h"
#include "mempool.h"

static trx_list_t *list;


extern void mempool_init() {
    list = transaction_list();
}


extern void mempool_add(trx_t *trx) {
    transaction_append(list, trx);
}


extern trx_t * mempool_remove(unsigned int id) {
    trx_t *t = transaction_find(list, id);
    if (t != NULL) {
        transaction_remove(list, t);
    }
    return t;
}


extern trx_t * mempool_select(int max_size) {
    if (list->head != NULL) {
        if (max_size >= transaction_size(list->head)) {
            return transaction_pop(list);
        }
    }
    return NULL;
}

extern void priotise_txt(){
    if(list->head!=NULL){
        transaction_priotise(list);
    }
}
