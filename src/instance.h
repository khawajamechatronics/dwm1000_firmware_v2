#ifndef _INSTANCE_H_
#define _INSTANCE_H_

#include "deca_types.h"
#include "deca_device_api.h"

#define RX_BUF_LEN 128
#define UUS_TO_DWT_TIME 65536
#define POLL_RX_TO_RESP_TX_DLY_UUS 600
#define TX_ANT_DLY 16436
#define RX_ANT_DLY 16436
#define POLL_TX_TO_RESP_RX_DLY_UUS 140
#define RESP_RX_TIMEOUT_UUS 210
#define SPEED_OF_LIGHT 299702547
#define RESP_MSG_TS_LEN 4
#define RESP_MSG_POLL_DELAY_IDX 9

#define STATUS_IDLE 0
#define STATUS_POLL 1

#define TDOA_INIT 1
#define TDOA_SEND 2

#define USART_MSG 0x00
#define USART_BEACON 0x01
#define USART_SETADDR 0x02
#define USART_RST 0x03
#define USART_AUTOBEACON 0x04
#define USART_LOG 0x05
#define USART_KEEPSILENT 0x06
#define USART_CLKSYNC 0x07
#define USART_TS 0x08

#ifdef __cplusplus
extern "C" {
#endif

void set_status(const uint8 s);
void set_mac(uint16 dmac);
void set_pan(uint16 dpan);
void set_src(uint8 *buf);
void set_dst(uint8 *buf, uint8 *addr);
int check_addr(uint8 *buf);
void instance_rxcallback(const dwt_callback_data_t *rxd);
void instance_txcallback(const dwt_callback_data_t *txd);
void instance_init();
uint64 get_rx_timestamp_u64(void);
uint64 get_tx_timestamp_u64(void);
void resp_msg_get_ts(uint8 *ts_field, uint64 *ts, int len);
void resp_msg_set_ts(uint8 *ts_field, const uint64 ts, int len);
void calculate_distance(uint8 *target);
void response_poll(uint8 *target);
void usart_handle(void);
void main_loop(void);
void beacon(void);
void tdoa_beacon(uint8 id);

#ifdef __cplusplus
}
#endif

#endif
