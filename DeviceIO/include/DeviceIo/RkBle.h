#ifndef __BLUETOOTH_BLE_H__
#define __BLUETOOTH_BLE_H__

#include <DeviceIo/RkBtBase.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	RK_BLE_STATE_IDLE = 0,
	RK_BLE_STATE_CONNECT,
	RK_BLE_STATE_DISCONNECT
} RK_BLE_STATE;

typedef struct {
	char uuid[38];
	char data[134];
	int len;
} RkBleConfig;

typedef void (*RK_BLE_STATE_CALLBACK)(const char *bd_addr, const char *name, RK_BLE_STATE state);
typedef void (*RK_BLE_RECV_CALLBACK)(const char *uuid, char *data, int len);

int rk_ble_register_status_callback(RK_BLE_STATE_CALLBACK cb);
int rk_ble_register_recv_callback(RK_BLE_RECV_CALLBACK cb);
int rk_ble_start(RkBleContent *ble_content);
int rk_ble_stop(void);
int rk_ble_get_state(RK_BLE_STATE *p_state);
int rk_ble_write(const char *uuid, char *data, int len);
int rk_ble_disconnect(void);
int rk_bt_ble_set_visibility(const int visiable, const int connect);
void rk_ble_set_local_privacy(bool local_privacy);

/*smallest value: 32(32 * 0.625ms = 20ms)*/
int rk_ble_set_adv_interval(unsigned short adv_int_min, unsigned short adv_int_max);

#ifdef __cplusplus
}
#endif

#endif /* __BLUETOOTH_BLE_H__ */
