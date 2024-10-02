/*************
 *
 *  Package Name:   QAPI - remote API based on QMI-framework
 *
 *  Purpose:        This package manages remote APIs between the apps
 *                  and modem processors
 *
 * Copyright: (c) 2020 WOORINET. All rights reserved.
 *
 *
 * This module creates a shared connection between a server task
 * (QCSI) on one processor and one or more client tasks (QCCI) on the
 * other processor.
 *
 * The same client and server code compiles and runs on both the
 * application processor and the modem processor.  This makes the
 * module easier to maintain because all client and server instances
 * are running the same code.
 *
 * Multiple instances, or connections, are also supported by allowing
 * multiple pairs of QCSI and QCCI tasks.
 *
 *
 * Server Side (QCSI):
 * ------------------
 *
 * The server task is capable of supporting multiple request messages.
 * Each request message is handled by a service, or service handler.
 *
 * !!! DO NOT ADD MESSAGE-SPECIFIC HANDLING TO THE QAPI MODULE !!!
 *
 * The service handlers are not part of the QAPI module.  Service
 * handlers are registered from outside of the QAPI using the service
 * registration function.  The one exception to this is the ping
 * handler, which is implemented in this module and is registered by
 * the QAPI QSCI at startup.  The ping service is included in the QAPI
 * module because it is used to confirm that a client-server link is
 * established, and is therefore inherent in the QAPI design.
 *
 * Service handlers are called from a common task context: qapi_qcsi_task()
 *
 * !!! SERVICE HANDLERS SHOULD NOT MAKE BLOCKING CALLS !!!
 *
 * Otherwise, other incomming requests will be delayed.  When long
 * operations such as file i/o, are required, service handlers should
 * process requests in a separate task and call the response function
 * from there.
 *
 * Service handlers must set the status field of the response message.
 *
 * NOTE: A server instance can support multiple clients, even from
 * different processes.  E.g. more than one client task on the
 * application processor may connect to a QAPI server on the modem in
 * order to access NV or file system items.
 *
 *
 * Client Side (QCCI):
 * ------------------
 *
 * The job of the QCCI task is to maintain the connection to a service
 * The users of the QCCI API must register by calling:
 *
 *   qapi_qcci_register()
 *
 * in order to receive a handle.  The handle is used for all future
 * requests.
 *
 * Clients must register separately to receive indications.  This is
 * done after calling qapi_qcci_register() using:
 *
 *   qapi_qcci_indication_register()
 *
 * The QAPI QCCI module provides both blocking and non-blocking APIs
 * for sending requests to the service.  Blocking occurs in the caller
 * task using a semaphore, and the watchdog is NOT serviced.  The
 * blocking API does not cause the qapi_qcci_task to be blocked.
 *
 * If a server disconnects while callers are blocked on a request, the
 * disconnect callback will be called FIRST, and then the request
 * function will unblock
 *
 *
 * Adding a Remote API (service):
 * -----------------------------
 *
 * NOTE:  General rules need to be followed to maintain compatibilty
 *        between API releases. See QCT doc:
 *        80-N0846-1 "QCT API Guidelines and Tools"
 *
 *
 * 1. Define the new message structures in either the common IDL file:
 *    qapi/src/IDL_files/qapi_common_v01.idl
 *
 *    Or, in a new one of your choice.  Use the same naming
 *    conventions for new files
 *
 *
 * 2. Add the message IDs to the IDL file for the processor on which
 *    the service will be supported.  It is harmless to add to both.
 *    E.g.
 *
 *    qapi/src/IDL_files/qapi_apss_0_v01.idl  - apps server 0
 *    qapi/src/IDL_files/qapi_mpss_0_v01.idl  - modem server 0
 *
 *    If creating a new IDL file for messages, add an include
 *    directive for it to the top of these server IDL files
 *
 *
 * 3. Run the IDL compiler on the three files (can use the -a option)
 *
 *    qmi_idl_compiler.pl -a
 *
 *    The most recently tested version is: 6.14.9, which works on a
 *    64-bit host.
 *
 *
 *  4. Review the message spec doc by checking the generated HTML file
 *     (generated *.c files normally don't need to be reviewed)
 *
 *
 *  5. Copy generated *.c, *.h, *.html and *.css to related source folders.
 *
 *     qapi/api/qapi_common_v01.h
 *     qapi/api/qapi_apss_0_v01.h
 *     qapi/api/qapi_mpss_0_v01.h
 *
 *     qapi/src/qapi_common_v01.c
 *     qapi/src/qapi_apss_0_v01.c
 *     qapi/src/qapi_mpss_0_v01.c
 *
 *     qapi/doc/qapi_common_wireformat_v01.html
 *     qapi/doc/qmi_idl_wiredoc.css
 *
 *
 *  6. The IDL compiler does not support more than one service
 *     definition per IDL file.  This is why there are separate IDL
 *     files for the apps and modem service definitions.
 *     Unfortunately, this results in the message IDs being defined in
 *     both of the resulting .h files.  As a workaround, copy the full
 *     set of message ID defines to qapi_common_v01.h and undefine
 *     them in qapi_apss_0_v01.c and qapi_mpss_0_v01.c, etc.
 *
 *
 *  7. Write service handlers in your separtate module and register
 *     them with the QAPI via qapi_qcsi_handler_register()
 *
 *
 */

/*
 * Example Service Handler
 */

/*
 * Example Client
 */
