#ifndef _DEPLOY_CONFIG_H__
#define _DEPLOY_CONFIG_H__


#define EASYQ_RECV_BUFFER_SIZE  4096
#define EASYQ_SEND_BUFFER_SIZE  512 
#define EASYQ_PORT				1085

#define EASYQ_LOGIN				"amp"
#define STATUS_QUEUE			EASYQ_LOGIN":status"
#define FOTA_QUEUE				EASYQ_LOGIN":fota"
#define FOTA_STATUS_QUEUE		EASYQ_LOGIN":fota:status"

#define VOLUME_QUEUE				EASYQ_LOGIN":volume"


#define WIFI_LED_MUX		PERIPHS_IO_MUX_U0TXD_U
#define WIFI_LED_NUM		1
#define WIFI_LED_FUNC		FUNC_GPIO1

#endif

