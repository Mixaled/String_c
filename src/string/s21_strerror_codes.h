#ifdef APPLE
char *ErrorNames[] = {"Undefined error: 0",
                      "Operation not permitted",
                      "No such file or directory",
                      "No such process",
                      "Interrupted system call",
                      "Input/output error",
                      "Device not configured",
                      "Argument list too long",
                      "Exec format error",
                      "Bad file descriptor",
                      "No child processes",
                      "Resource deadlock avoided",
                      "Cannot allocate memory",
                      "Permission denied",
                      "Bad address",
                      "Block device required",
                      "Resource busy",
                      "File exists",
                      "Cross-device link",
                      "Operation not supported by device",
                      "Not a directory",
                      "Is a directory",
                      "Invalid argument",
                      "Too many open files in system",
                      "Too many open files",
                      "Inappropriate ioctl for device",
                      "Text file busy",
                      "File too large",
                      "No space left on device",
                      "Illegal seek",
                      "Read-only file system",
                      "Too many links",
                      "Broken pipe",
                      "Numerical argument out of domain",
                      "Result too large",
                      "Resource temporarily unavailable",
                      "Operation now in progress",
                      "Operation already in progress",
                      "Socket operation on non-socket",
                      "Destination address required",
                      "Message too long",
                      "Protocol wrong type for socket",
                      "Protocol not available",
                      "Protocol not supported",
                      "Socket type not supported",
                      "Operation not supported",
                      "Protocol family not supported",
                      "Address family not supported by protocol family",
                      "Address already in use",
                      "Can't assign requested address",
                      "Network is down",
                      "Network is unreachable",
                      "Network dropped connection on reset",
                      "Software caused connection abort",
                      "Connection reset by peer",
                      "No buffer space available",
                      "Socket is already connected",
                      "Socket is not connected",
                      "Can't send after socket shutdown",
                      "Too many references: can't splice",
                      "Operation timed out",
                      "Connection refused",
                      "Too many levels of symbolic links",
                      "File name too long",
                      "Host is down",
                      "No route to host",
                      "Directory not empty",
                      "Too many processes",
                      "Too many users",
                      "Disc quota exceeded",
                      "Stale NFS file handle",
                      "Too many levels of remote in path",
                      "RPC struct is bad",
                      "RPC version wrong",
                      "RPC prog. not avail",
                      "Program version wrong",
                      "Bad procedure for program",
                      "No locks available",
                      "Function not implemented",
                      "Inappropriate file type or format",
                      "Authentication error",
                      "Need authenticator",
                      "Device power is off",
                      "Device error",
                      "Value too large to be stored in data type",
                      "Bad executable (or shared library)",
                      "Bad CPU type in executable",
                      "Shared library version mismatch",
                      "Malformed Mach-o file",
                      "Operation canceled",
                      "Identifier removed",
                      "No message of desired type",
                      "Illegal byte sequence",
                      "Attribute not found",
                      "Bad message",
                      "EMULTIHOP (Reserved)",
                      "No message available on STREAM",
                      "ENOLINK (Reserved)",
                      "No STREAM resources",
                      "Not a STREAM",
                      "Protocol error",
                      "STREAM ioctl timeout",
                      "Operation not supported on socket",
                      "Policy not found",
                      "State not recoverable",
                      "Previous owner died",
                      "Interface output queue is full"};

enum Errors {
  Undefined_error_0,
  Operation_not_permitted,
  No_such_file_or_directory,
  No_such_process,
  Interrupted_system_call,
  Input_output_error,
  Device_not_configured,
  Argument_list_too_long,
  Exec_format_error,
  Bad_file_descriptor,
  No_child_processes,
  Resource_deadlock_avoided,
  Cannot_allocate_memory,
  Permission_denied,
  Bad_address,
  Block_device_required,
  Resource_busy,
  File_exists,
  Cross_device_link,
  Operation_not_supported_by_device,
  Not_a_directory,
  Is_a_directory,
  Invalid_argument,
  Too_many_open_files_in_system,
  Too_many_open_files,
  Inappropriate_ioctl_for_device,
  Text_file_busy,
  File_too_large,
  No_space_left_on_device,
  Illegal_seek,
  Read_only_file_system,
  Too_many_links,
  Broken_pipe,
  Numerical_argument_out_of_domain,
  Result_too_large,
  Resource_temporarily_unavailable,
  Operation_now_in_progress,
  Operation_already_in_progress,
  Socket_operation_on_non_socket,
  Destination_address_required,
  Message_too_long,
  Protocol_wrong_type_for_socket,
  Protocol_not_available,
  Protocol_not_supported,
  Socket_type_not_supported,
  Operation_not_supported,
  Protocol_family_not_supported,
  Address_family_not_supported_by_protocol_family,
  Address_already_in_use,
  Cant_assign_requested_address,
  Network_is_down,
  Network_is_unreachable,
  Network_dropped_connection_on_reset,
  Software_caused_connection_abort,
  Connection_reset_by_peer,
  No_buffer_space_available,
  Socket_is_already_connected,
  Socket_is_not_connected,
  Cant_send_after_socket_shutdown,
  Too_many_references_cant_splice,
  Operation_timed_out,
  Connection_refused,
  Too_many_levels_of_symbolic_links,
  File_name_too_long,
  Host_is_down,
  No_route_to_host,
  Directory_not_empty,
  Too_many_processes,
  Too_many_users,
  Disc_quota_exceeded,
  Stale_NFS_file_handle,
  Too_many_levels_of_remote_in_path,
  RPC_struct_is_bad,
  RPC_version_wrong,
  RPC_prog_not_avail,
  Program_version_wrong,
  Bad_procedure_for_program,
  No_locks_available,
  Function_not_implemented,
  Inappropriate_file_type_or_format,
  Authentication_error,
  Need_authenticator,
  Device_power_is_off,
  Device_error,
  Value_too_large_to_be_stored_in_data_type,
  Bad_executable_or_shared_library,
  Bad_CPU_type_in_executable,
  Shared_library_version_mismatch,
  Malformed_Mach_o_file,
  Operation_canceled,
  Identifier_removed,
  No_message_of_desired_type,
  Illegal_byte_sequence,
  Attribute_not_found,
  Bad_message,
  EMULTIHOP_Reserved,
  No_message_available_on_STREAM,
  ENOLINK_Reserved,
  No_STREAM_resources,
  Not_a_STREAM,
  Protocol_error,
  STREAM_ioctl_timeout,
  Operation_not_supported_on_socket,
  Policy_not_found,
  State_not_recoverable,
  Previous_owner_died,
  Interface_output_queue_is_full
};
#endif

#ifdef LINUX
char *ErrorNamesLinux[] = {"Success",
                           "Operation not permitted",
                           "No such file or directory",
                           "No such process",
                           "Interrupted system call",
                           "Input/output error",
                           "No such device or address",
                           "Argument list too long",
                           "Exec format error",
                           "Bad file descriptor",
                           "No child processes",
                           "Resource temporarily unavailable",
                           "Cannot allocate memory",
                           "Permission denied",
                           "Bad address",
                           "Block device required",
                           "Device or resource busy",
                           "File exists",
                           "Invalid cross-device link",
                           "No such device",
                           "Not a directory",
                           "Is a directory",
                           "Invalid argument",
                           "Too many open files in system",
                           "Too many open files",
                           "Inappropriate ioctl for device",
                           "Text file busy",
                           "File too large",
                           "No space left on device",
                           "Illegal seek",
                           "Read-only file system",
                           "Too many links",
                           "Broken pipe",
                           "Numerical argument out of domain",
                           "Numerical result out of range",
                           "Resource deadlock avoided",
                           "File name too long",
                           "No locks available",
                           "Function not implemented",
                           "Directory not empty",
                           "Too many levels of symbolic links",
                           "Unknown error 41",
                           "No message of desired type",
                           "Identifier removed",
                           "Channel number out of range",
                           "Level 2 not synchronized",
                           "Level 3 halted",
                           "Level 3 reset",
                           "Link number out of range",
                           "Protocol driver not attached",
                           "No CSI structure available",
                           "Level 2 halted",
                           "Invalid exchange",
                           "Invalid request descriptor",
                           "Exchange full",
                           "No anode",
                           "Invalid request code",
                           "Invalid slot",
                           "Unknown error 58",
                           "Bad font file format",
                           "Device not a stream",
                           "No data available",
                           "Timer expired",
                           "Out of streams resources",
                           "Machine is not on the network",
                           "Package not installed",
                           "Object is remote",
                           "Link has been severed",
                           "Advertise error",
                           "Srmount error",
                           "Communication error on send",
                           "Protocol error",
                           "Multihop attempted",
                           "RFS specific error",
                           "Bad message",
                           "Value too large for defined data type",
                           "Name not unique on network",
                           "File descriptor in bad state",
                           "Remote address changed",
                           "Can not access a needed shared library",
                           "Accessing a corrupted shared library",
                           ".lib section in a.out corrupted",
                           "Attempting to link in too many shared libraries",
                           "Cannot exec a shared library directly",
                           "Invalid or incomplete multibyte or wide character",
                           "Interrupted system call should be restarted",
                           "Streams pipe error",
                           "Too many users",
                           "Socket operation on non-socket",
                           "Destination address required",
                           "Message too long",
                           "Protocol wrong type for socket",
                           "Protocol not available",
                           "Protocol not supported",
                           "Socket type not supported",
                           "Operation not supported",
                           "Protocol family not supported",
                           "Address family not supported by protocol",
                           "Address already in use",
                           "Cannot assign requested address",
                           "Network is down",
                           "Network is unreachable",
                           "Network dropped connection on reset",
                           "Software caused connection abort",
                           "Connection reset by peer",
                           "No buffer space available",
                           "Transport endpoint is already connected",
                           "Transport endpoint is not connected",
                           "Cannot send after transport endpoint shutdown",
                           "Too many references: cannot splice",
                           "Connection timed out",
                           "Connection refused",
                           "Host is down",
                           "No route to host",
                           "Operation already in progress",
                           "Operation now in progress",
                           "Stale file handle",
                           "Structure needs cleaning",
                           "Not a XENIX named type file",
                           "No XENIX semaphores available",
                           "Is a named type file",
                           "Remote I/O error",
                           "Disk quota exceeded",
                           "No medium found",
                           "Wrong medium type",
                           "Operation canceled",
                           "Required key not available",
                           "Key has expired",
                           "Key has been revoked",
                           "Key was rejected by service",
                           "Owner died",
                           "State not recoverable",
                           "Operation not possible due to RF-kill",
                           "Memory page has hardware error"};

enum ErrorsLinux {
  Success_Linux,
  Operation_not_permitted_Linux,
  No_such_file_or_directory_Linux,
  No_such_process_Linux,
  Interrupted_system_call_Linux,
  Input_output_error_Linux,
  No_such_device_or_address_Linux,
  Argument_list_too_long_Linux,
  Exec_format_error_Linux,
  Bad_file_descriptor_Linux,
  No_child_processes_Linux,
  Resource_temporarily_unavailable_Linux,
  Cannot_allocate_memory_Linux,
  Permission_denied_Linux,
  Bad_address_Linux,
  Block_device_required_Linux,
  Device_or_resource_busy_Linux,
  File_exists_Linux,
  Invalid_cross_device_link_Linux,
  No_such_device_Linux,
  Not_a_directory_Linux,
  Is_a_directory_Linux,
  Invalid_argument_Linux,
  Too_many_open_files_in_system_Linux,
  Too_many_open_files_Linux,
  Inappropriate_ioctl_for_device_Linux,
  Text_file_busy_Linux,
  File_too_large_Linux,
  No_space_left_on_device_Linux,
  Illegal_seek_Linux,
  Read_only_file_system_Linux,
  Too_many_links_Linux,
  Broken_pipe_Linux,
  Numerical_argument_out_of_domain_Linux,
  Numerical_result_out_of_range_Linux,
  Resource_deadlock_avoided_Linux,
  File_name_too_long_Linux,
  No_locks_available_Linux,
  Function_not_implemented_Linux,
  Directory_not_empty_Linux,
  Too_many_levels_of_symbolic_links_Linux,
  Unknown_error_41_Linux,
  No_message_of_desired_type_Linux,
  Identifier_removed_Linux,
  Channel_number_out_of_range_Linux,
  Level_2_not_synchronized_Linux,
  Level_3_halted_Linux,
  Level_3_reset_Linux,
  Link_number_out_of_range_Linux,
  Protocol_driver_not_attached_Linux,
  No_CSI_structure_available_Linux,
  Level_2_halted_Linux,
  Invalid_exchange_Linux,
  Invalid_request_descriptor_Linux,
  Exchange_full_Linux,
  No_anode_Linux,
  Invalid_request_code_Linux,
  Invalid_slot_Linux,
  Unknown_error_58_Linux,
  Bad_font_file_format_Linux,
  Device_not_a_stream_Linux,
  No_data_available_Linux,
  Timer_expired_Linux,
  Out_of_streams_resources_Linux,
  Machine_is_not_on_the_network_Linux,
  Package_not_installed_Linux,
  Object_is_remote_Linux,
  Link_has_been_severed_Linux,
  Advertise_error_Linux,
  Srmount_error_Linux,
  Communication_error_on_send_Linux,
  Protocol_error_Linux,
  Multihop_attempted_Linux,
  RFS_specific_error_Linux,
  Bad_message_Linux,
  Value_too_large_for_defined_data_type_Linux,
  Name_not_unique_on_network_Linux,
  File_descriptor_in_bad_state_Linux,
  Remote_address_changed_Linux,
  Can_not_access_a_needed_shared_library_Linux,
  Accessing_a_corrupted_shared_library_Linux,
  lib_section_in_a_out_corrupted_Linux,
  Attempting_to_link_in_too_many_shared_libraries_Linux,
  Cannot_exec_a_shared_library_directly_Linux,
  Invalid_or_incomplete_multibyte_or_wide_character_Linux,
  Interrupted_system_call_should_be_restarted_Linux,
  Streams_pipe_error_Linux,
  Too_many_users_Linux,
  Socket_operation_on_non_socket_Linux,
  Destination_address_required_Linux,
  Message_too_long_Linux,
  Protocol_wrong_type_for_socket_Linux,
  Protocol_not_available_Linux,
  Protocol_not_supported_Linux,
  Socket_type_not_supported_Linux,
  Operation_not_supported_Linux,
  Protocol_family_not_supported_Linux,
  Address_family_not_supported_by_protocol_Linux,
  Address_already_in_use_Linux,
  Cannot_assign_requested_address_Linux,
  Network_is_down_Linux,
  Network_is_unreachable_Linux,
  Network_dropped_connection_on_reset_Linux,
  Software_caused_connection_abort_Linux,
  Connection_reset_by_peer_Linux,
  No_buffer_space_available_Linux,
  Transport_endpoint_is_already_connected_Linux,
  Transport_endpoint_is_not_connected_Linux,
  Cannot_send_after_transport_endpoint_shutdown_Linux,
  Too_many_references_cannot_splice_Linux,
  Connection_timed_out_Linux,
  Connection_refused_Linux,
  Host_is_down_Linux,
  No_route_to_host_Linux,
  Operation_already_in_progress_Linux,
  Operation_now_in_progress_Linux,
  Stale_file_handle_Linux,
  Structure_needs_cleaning_Linux,
  Not_a_XENIX_named_type_file_Linux,
  No_XENIX_semaphores_available_Linux,
  Is_a_named_type_file_Linux,
  Remote_I_O_error_Linux,
  Disk_quota_exceeded_Linux,
  No_medium_found_Linux,
  Wrong_medium_type_Linux,
  Operation_canceled_Linux,
  Required_key_not_available_Linux,
  Key_has_expired_Linux,
  Key_has_been_revoked_Linux,
  Key_was_rejected_by_service_Linux,
  Owner_died_Linux,
  State_not_recoverable_Linux,
  Operation_not_possible_due_to_RF_kill_Linux,
  Memory_page_has_hardware_error
};
#endif