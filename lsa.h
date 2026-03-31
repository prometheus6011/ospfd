#ifndef OSPF_LSA_H
#define OSPF_LSA_H

struct lsa_header {
    uint16_t lsa_age;
    uint8_t options;
    uint8_t lsa_type;
    struct in_addr link_state_id;
    struct in_addr advert_rtr_id;
    int32_t seq_num;
    uint16_t checksum;
    uint16_t length;
};

struct router_lsa {
    struct lsa_header header;
    uint8_t flags;
    uint8_t zero;
    uint16_t num_links;
    struct router_link {
        struct in_addr link_id;
        struct in_addr link_data;
        uint8_t type;
        uint8_t tos_count;
        uint16_t metric;
    } links[];
};

struct network_lsa {
    struct lsa_header header;
    struct in_addr network_mask;
    struct in_addr attached_rtrs[];
};

struct summary_lsa {
    struct lsa_header header;
    struct in_addr network_mask;
    uint8_t tos;
    uint8_t metric[3];
};

#endif  // OSPF_LSA_H
