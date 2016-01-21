
#ifndef __ARP_H__
#define __ARP_H__

/************************************************************************
 *
 * Here, you may add definitions needed for your implementation.
 *
 ************************************************************************/
//#include<cstdint>
//#include <stdint.h>
//#include <stddef.h>

//typedef uint16_t u_int16_t;
//typedef size_t size_type;

 /* ARP Header, (assuming Ethernet+IPv4)            */
#define ARP_REQUEST 1   /* ARP Request             */ 
#define ARP_REPLY 2     /* ARP Reply               */ 

#define PROTO_TYPE_IP 0x0800
#define ETHER_TYPE_ARP 0x0806
#define HW_TYPE_ETHER 0x0001
#define OP_CODE_ARPREQ 0x0001
#define HW_LEN_ETHER 0x06
#define HW_LEN_IP 0x04

typedef struct arphdr {
	WORD htype;    /* Hardware Type           */
	WORD ptype;    /* Protocol Type           */
	BYTE hlen;        /* Hardware Address Length */
	BYTE plen;        /* Protocol Address Length */
	WORD oper;     /* Operation Code          */
	BYTE sha[6];      /* Sender hardware address */
	BYTE spa[4];      /* Sender IP address       */
	BYTE tha[6];      /* Target hardware address */
	BYTE tpa[4];      /* Target IP address       */
	char fill[18];		/*Padding*/
}arphdr_t;


typedef struct cache {
	/*Status		IP		MAC address		Lifetime(sec) */
	WORD status;		/*Status of translation*/
	DWORD lifetime;   /*Life time of the entry*/
	BYTE tha[6];      /* Target hardware address */
	BYTE tpa[4];      /* Target IP address       */
	int value;
	struct cache *next;
}cache_t;

/*typedef struct list {

	int value;
	cache_t *cachelist;
};*/
struct cache *po ;

void ARP_Init(void);
void ARP_Cleanup(void);
void ARP_SecondProcessing(void);
void ARP_PrintAll(void);

PENETADDR ARP_Query(PIPADDR pIPAddr);
void ARP_ProcessIncoming(PVOID pData, DWORD dwLen);



#endif /* __ARP_H__ */
