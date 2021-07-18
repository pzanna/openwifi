/* Copyright (c) 2017 Northbound Networks
 *
 * Written By Paul Zanna (paul@northboundnetworks.com)
 *
 */

/*
#define BUFLEN 65536

#define MAX_FLOWS    512
#define MAX_TABLES      16
#define SHARED_BUFFER_LEN 16384
#define PACKET_BUFFER 32
#define PACKET_BUFFER_SIZE 256
#define PB_EMPTY 0
#define PB_PACKETIN 1
#define PB_PACKETOUT 2
#define PB_PENDING 3
*/

#define TABLE_SIZE 256
#define PACKET_BUFFER 64
#define PB_EMPTY 0
#define PB_PENDING 1

#define VERSION 0.3

struct rfFeatures_t {
    int64_t timestamp; /* int<64> */
    int16_t rssi; /* int<16> */
    int16_t blank; /* int<16> */
    int16_t len; /* int<16> */
    int16_t rate_idx; /* int<16> */
    int32_t phaseOffset; /* int<32> */
    int32_t pilotOffset; /* int<32> */
    int32_t magSq; /* int<32> */
    int32_t aux_4; /* int<32> */
    uint8_t wp4_valid;
};
struct frameCtrl_t {
    uint8_t protoVer; /* bit<2> */
    uint8_t frameType; /* bit<2> */
    uint8_t subType; /* bit<4> */
    uint8_t toDS; /* bit<1> */
    uint8_t fromDS; /* bit<1> */
    uint8_t moreFrag; /* bit<1> */
    uint8_t retry; /* bit<1> */
    uint8_t pwrMgmt; /* bit<1> */
    uint8_t moreData; /* bit<1> */
    uint8_t protFrame; /* bit<1> */
    uint8_t order; /* bit<1> */
    uint8_t wp4_valid;
};
struct mac80211_t {
    uint16_t durID; /* bit<16> */
    uint64_t Addr1; /* macAddr_t */
    uint64_t Addr2; /* macAddr_t */
    uint64_t Addr3; /* macAddr_t */
    uint16_t seqCtrl; /* bit<16> */
    uint64_t Addr4; /* macAddr_t */
    uint8_t wp4_valid;
};
struct Headers_t {
    struct rfFeatures_t rfFeatures; /* rfFeatures_t */
    struct frameCtrl_t frameCtrl; /* frameCtrl_t */
    struct mac80211_t mac80211; /* mac80211_t */
};

struct swtch_lookup_tbl_key {
    uint64_t headers_mac80211_Addr2_class; /* headers.mac80211.Addr2_class */
    uint32_t headers_rfFeatures_phaseOffset_max; /* headers.rfFeatures.phaseOffset_max */
    uint32_t headers_rfFeatures_phaseOffset_min; /* headers.rfFeatures.phaseOffset_min */
    uint16_t headers_rfFeatures_rssi_max; /* headers.rfFeatures.rssi_max */
    uint16_t headers_rfFeatures_rssi_min; /* headers.rfFeatures.rssi_min */
    uint8_t headers_frameCtrl_subType_exact; /* headers.frameCtrl.subType_exact */
    uint8_t headers_frameCtrl_frameType_exact; /* headers.frameCtrl.frameType_exact */
};

struct rule_scope {
    uint8_t headers_mac80211_Addr2_class;
    uint8_t headers_rfFeatures_phaseOffset_max;
    uint8_t headers_rfFeatures_phaseOffset_min;
    uint8_t headers_rfFeatures_rssi_max;
    uint8_t headers_rfFeatures_rssi_min;
    uint8_t headers_frameCtrl_subType_exact;
    uint8_t headers_frameCtrl_frameType_exact;
};

struct rule_metadata {
	uint8_t valid;
    uint64_t numerosity;
    uint64_t match_count;
    uint64_t correct_count;
    uint64_t accuracy;
    uint64_t fitness;
    uint64_t age;
};

struct wp4_map_def {
    uint16_t key_size;
    uint16_t value_size;
    uint16_t max_entries;
    uint16_t last_entry;
    time_t last_lookup;
    struct swtch_lookup_tbl_key key[TABLE_SIZE];
    struct rule_scope scope[TABLE_SIZE];
    struct rule_metadata rule_data[TABLE_SIZE];
    uint8_t action[TABLE_SIZE];
};

struct packet_buffer
{
    uint8_t flow;
    uint8_t type;
    struct Headers_t buffer;
};

struct pbuffer
{
    struct packet_buffer buffer[PACKET_BUFFER];
};

/*
struct packet_out
{
    uint32_t inport;
    uint32_t outport;
    //uint32_t sk_buff *skb; 
};
*/

