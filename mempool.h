

#ifndef MEMPOOL_H
#define MEMPOOL_H
#include "transactions.h"

extern void mempool_init();
extern void mempool_add(trx_t *trx);
extern trx_t * mempool_remove(unsigned int id);
extern trx_t * mempool_select(int max_size);
extern void priotise_txt(void);

#endif //MINER_MEMPOOL_H
