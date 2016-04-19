/*
 * USB_VCP.c
 *
 * Created: 3/21/2016 5:10:49 PM
 *  Author: akr72
 */ 

#include "USB_VCP.h"

void vcp_transmit_bytes(uint8_t * data, uint8_t length)
{
	for(int i = 0; i < length; i++){
		udi_cdc_putc(data[i]);
	}
}

void vcp_rx_notify(uint8_t port)
{
	
	vcp_echo(udi_cdc_getc());
	// Do something about it.
}

void vcp_echo(uint8_t data)
{
	udi_cdc_putc(data);
	
	if(udi_cdc_is_rx_ready()){
		if (!udi_cdc_is_tx_ready()) {
			udi_cdc_signal_overrun();
		} else {
			udi_cdc_putc(udi_cdc_getc());
		}
	}
}

void ui_init(void)
{

}

void ui_powerdown(void)
{
}

#ifdef USB_DEVICE_LPM_SUPPORT
void ui_wakeup_enable(void)
{
}

void ui_wakeup_disable(void)
{
}
#endif // #ifdef USB_DEVICE_LPM_SUPPORT

void ui_wakeup(void)
{
}


void ui_com_open(uint8_t port)
{
	UNUSED(port);
}


void ui_com_close(uint8_t port)
{
	UNUSED(port);
}


void ui_com_rx_start(void)
{

}


void ui_com_rx_stop(void)
{

}


void ui_com_tx_start(void)
{

}


void ui_com_tx_stop(void)
{

}


void ui_com_error(void)
{

}


void ui_com_overflow(void)
{

}

void ui_process(uint16_t framenumber)
{

}
