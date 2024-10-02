/************
 *
 * Filename:  qapiuproto.h
 *
 * Purpose:   external prototypes for QAPI package
 *
 * Copyright: (c) 2020 WOORINET. All rights reserved.
 *
 ************/

/*
 * QCCI (client) and QCSI (server) routines, common to both processors
 *
 * Note: implementations differ for each processor
 */

/* Client task */
extern void qapi_qcci_task(void * parmp);
extern void qapi_qcci_init(void);

/* Server task */
extern void qapi_qcsi_task(void * param);
extern void qapi_qcsi_init(void);

/*
 * Server API
 *
 * Services register handlers to service a particular type of request
 * (msg_id) from clients
 *
 * Services use the response and indication functions to reply to
 * the client's request
 */
extern boolean qapi_qcsi_handler_register(enum qapi_service_id_e service_id,
                                          unsigned int           msg_id,
                                          qapi_qcsi_req_handler  service_request_cb,
                                          qapi_qcsi_cli_conn_cb  client_connect_cb,
                                          qapi_qcsi_cli_conn_cb  client_disconn_cb,
                                          void                  *handler_context);

extern boolean qapi_qcsi_handler_deregister(enum qapi_service_id_e service_id,
                                            unsigned int           msg_id);

extern boolean qapi_qcsi_resp_send(qapi_qcsi_req_handle req_handle,
                                   unsigned int         msg_id,
                                   void                *c_struct,
                                   unsigned int         c_struct_len);

extern boolean qapi_qcsi_ind_send(enum qapi_service_id_e service_id,
                                  qapi_qcsi_cli_handle   client,
                                  unsigned int           msg_id,
                                  void                  *c_struct,
                                  unsigned int           c_struct_len);


/*
 * Client API
 */
extern boolean qapi_qcci_register(unsigned int             number,
                                  qapi_qcci_client_handle *handle,
                                  qapi_qcci_ind_callback   indication_cb,
                                  qapi_qcci_conn_callback  connect_cb,
                                  qapi_qcci_conn_callback  disconn_cb,
                                  void                    *cb_data);

extern boolean qapi_qcci_deregister(qapi_qcci_client_handle handle);

extern boolean qapi_qcci_indication_register(qapi_qcci_client_handle handle,
                                             unsigned int            msg_id);

extern boolean qapi_qcci_indication_deregister(qapi_qcci_client_handle handle,
                                               unsigned int            msg_id);

extern boolean qapi_qcci_request_send(qapi_qcci_client_handle handle,
                                      int                     msg_id,
                                      void                   *data_req,
                                      int                     data_req_size,
                                      void                   *data_resp,
                                      int                     data_resp_size);

extern boolean qapi_qcci_request_send_async(qapi_qcci_client_handle  handle,
                                            int                      qmicmd,
                                            void                    *data_req,
                                            int                      data_req_size,
                                            void                    *data_resp,
                                            int                      data_resp_size,
                                            qapi_qcci_resp_callback  async_cb,
                                            void                    *async_cb_data);

extern boolean qapi_qcci_comm_status_get(void);

extern boolean qapi_qcci_halt_for_qmi_ready(void         *tcb,
                                            unsigned int  retries,
                                            unsigned int  interval_ms);
#ifdef WOORINET_IMAGE_MODEM
extern void qapi_remote_cli_init(void);
extern boolean qapi_wakelock_wakelock_req(uint16 optype,
                                          const char* name);
extern boolean qapi_linux_popen_linux_popen_req(const char* cmdp,
                                                size_t  respsz,
                                                char* resp);
#endif
