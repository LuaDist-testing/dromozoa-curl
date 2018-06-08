// generated from curl-7.52.1

#include "common.hpp"
#include "symbols.hpp"

namespace dromozoa {
  void initialize_symbols(lua_State* L) {
    luaX_set_field<lua_Integer>(L, -1, "CURLAUTH_ANY", CURLAUTH_ANY);
    luaX_set_field<lua_Integer>(L, -1, "CURLAUTH_ANYSAFE", CURLAUTH_ANYSAFE);
    luaX_set_field<lua_Integer>(L, -1, "CURLAUTH_BASIC", CURLAUTH_BASIC);
    luaX_set_field<lua_Integer>(L, -1, "CURLAUTH_DIGEST", CURLAUTH_DIGEST);
#if 0x071303 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLAUTH_DIGEST_IE", CURLAUTH_DIGEST_IE);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLAUTH_GSSNEGOTIATE", CURLAUTH_GSSNEGOTIATE);
#if 0x072600 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLAUTH_NEGOTIATE", CURLAUTH_NEGOTIATE);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLAUTH_NONE", CURLAUTH_NONE);
    luaX_set_field<lua_Integer>(L, -1, "CURLAUTH_NTLM", CURLAUTH_NTLM);
#if 0x071600 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLAUTH_NTLM_WB", CURLAUTH_NTLM_WB);
#endif
#if 0x071503 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLAUTH_ONLY", CURLAUTH_ONLY);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLCLOSEPOLICY_CALLBACK", CURLCLOSEPOLICY_CALLBACK);
    luaX_set_field<lua_Integer>(L, -1, "CURLCLOSEPOLICY_LEAST_RECENTLY_USED", CURLCLOSEPOLICY_LEAST_RECENTLY_USED);
    luaX_set_field<lua_Integer>(L, -1, "CURLCLOSEPOLICY_LEAST_TRAFFIC", CURLCLOSEPOLICY_LEAST_TRAFFIC);
    luaX_set_field<lua_Integer>(L, -1, "CURLCLOSEPOLICY_NONE", CURLCLOSEPOLICY_NONE);
    luaX_set_field<lua_Integer>(L, -1, "CURLCLOSEPOLICY_OLDEST", CURLCLOSEPOLICY_OLDEST);
    luaX_set_field<lua_Integer>(L, -1, "CURLCLOSEPOLICY_SLOWEST", CURLCLOSEPOLICY_SLOWEST);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_ABORTED_BY_CALLBACK", CURLE_ABORTED_BY_CALLBACK);
#if 0x071202 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLE_AGAIN", CURLE_AGAIN);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLE_ALREADY_COMPLETE", CURLE_ALREADY_COMPLETE);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_BAD_CONTENT_ENCODING", CURLE_BAD_CONTENT_ENCODING);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_BAD_DOWNLOAD_RESUME", CURLE_BAD_DOWNLOAD_RESUME);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_BAD_FUNCTION_ARGUMENT", CURLE_BAD_FUNCTION_ARGUMENT);
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLE_CHUNK_FAILED", CURLE_CHUNK_FAILED);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLE_CONV_FAILED", CURLE_CONV_FAILED);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_CONV_REQD", CURLE_CONV_REQD);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_COULDNT_CONNECT", CURLE_COULDNT_CONNECT);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_COULDNT_RESOLVE_HOST", CURLE_COULDNT_RESOLVE_HOST);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_COULDNT_RESOLVE_PROXY", CURLE_COULDNT_RESOLVE_PROXY);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_FAILED_INIT", CURLE_FAILED_INIT);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_FILESIZE_EXCEEDED", CURLE_FILESIZE_EXCEEDED);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_FILE_COULDNT_READ_FILE", CURLE_FILE_COULDNT_READ_FILE);
#if 0x071800 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLE_FTP_ACCEPT_FAILED", CURLE_FTP_ACCEPT_FAILED);
#endif
#if 0x071800 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLE_FTP_ACCEPT_TIMEOUT", CURLE_FTP_ACCEPT_TIMEOUT);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLE_FTP_ACCESS_DENIED", CURLE_FTP_ACCESS_DENIED);
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLE_FTP_BAD_FILE_LIST", CURLE_FTP_BAD_FILE_LIST);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLE_FTP_CANT_GET_HOST", CURLE_FTP_CANT_GET_HOST);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_FTP_COULDNT_RETR_FILE", CURLE_FTP_COULDNT_RETR_FILE);
#if 0x071100 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLE_FTP_COULDNT_SET_TYPE", CURLE_FTP_COULDNT_SET_TYPE);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLE_FTP_COULDNT_STOR_FILE", CURLE_FTP_COULDNT_STOR_FILE);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_FTP_COULDNT_USE_REST", CURLE_FTP_COULDNT_USE_REST);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_FTP_PORT_FAILED", CURLE_FTP_PORT_FAILED);
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLE_FTP_PRET_FAILED", CURLE_FTP_PRET_FAILED);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLE_FTP_WEIRD_227_FORMAT", CURLE_FTP_WEIRD_227_FORMAT);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_FTP_WEIRD_PASS_REPLY", CURLE_FTP_WEIRD_PASS_REPLY);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_FTP_WEIRD_PASV_REPLY", CURLE_FTP_WEIRD_PASV_REPLY);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_FTP_WEIRD_SERVER_REPLY", CURLE_FTP_WEIRD_SERVER_REPLY);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_FUNCTION_NOT_FOUND", CURLE_FUNCTION_NOT_FOUND);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_GOT_NOTHING", CURLE_GOT_NOTHING);
#if 0x072600 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLE_HTTP2", CURLE_HTTP2);
#endif
#if 0x073100 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLE_HTTP2_STREAM", CURLE_HTTP2_STREAM);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLE_HTTP_NOT_FOUND", CURLE_HTTP_NOT_FOUND);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_HTTP_POST_ERROR", CURLE_HTTP_POST_ERROR);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_HTTP_RETURNED_ERROR", CURLE_HTTP_RETURNED_ERROR);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_INTERFACE_FAILED", CURLE_INTERFACE_FAILED);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_LDAP_CANNOT_BIND", CURLE_LDAP_CANNOT_BIND);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_LDAP_INVALID_URL", CURLE_LDAP_INVALID_URL);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_LDAP_SEARCH_FAILED", CURLE_LDAP_SEARCH_FAILED);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_LOGIN_DENIED", CURLE_LOGIN_DENIED);
#if 0x071505 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLE_NOT_BUILT_IN", CURLE_NOT_BUILT_IN);
#endif
#if 0x071e00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLE_NO_CONNECTION_AVAILABLE", CURLE_NO_CONNECTION_AVAILABLE);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLE_OK", CURLE_OK);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_OPERATION_TIMEDOUT", CURLE_OPERATION_TIMEDOUT);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_OUT_OF_MEMORY", CURLE_OUT_OF_MEMORY);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_PARTIAL_FILE", CURLE_PARTIAL_FILE);
#if 0x071101 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLE_PEER_FAILED_VERIFICATION", CURLE_PEER_FAILED_VERIFICATION);
#endif
#if 0x071100 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLE_QUOTE_ERROR", CURLE_QUOTE_ERROR);
#endif
#if 0x071100 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLE_RANGE_ERROR", CURLE_RANGE_ERROR);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLE_READ_ERROR", CURLE_READ_ERROR);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_RECV_ERROR", CURLE_RECV_ERROR);
#if 0x071100 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLE_REMOTE_ACCESS_DENIED", CURLE_REMOTE_ACCESS_DENIED);
#endif
#if 0x071100 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLE_REMOTE_DISK_FULL", CURLE_REMOTE_DISK_FULL);
#endif
#if 0x071100 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLE_REMOTE_FILE_EXISTS", CURLE_REMOTE_FILE_EXISTS);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLE_REMOTE_FILE_NOT_FOUND", CURLE_REMOTE_FILE_NOT_FOUND);
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLE_RTSP_CSEQ_ERROR", CURLE_RTSP_CSEQ_ERROR);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLE_RTSP_SESSION_ERROR", CURLE_RTSP_SESSION_ERROR);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLE_SEND_ERROR", CURLE_SEND_ERROR);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_SEND_FAIL_REWIND", CURLE_SEND_FAIL_REWIND);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_SSH", CURLE_SSH);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_SSL_CACERT", CURLE_SSL_CACERT);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_SSL_CACERT_BADFILE", CURLE_SSL_CACERT_BADFILE);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_SSL_CERTPROBLEM", CURLE_SSL_CERTPROBLEM);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_SSL_CIPHER", CURLE_SSL_CIPHER);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_SSL_CONNECT_ERROR", CURLE_SSL_CONNECT_ERROR);
#if 0x071300 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLE_SSL_CRL_BADFILE", CURLE_SSL_CRL_BADFILE);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLE_SSL_ENGINE_INITFAILED", CURLE_SSL_ENGINE_INITFAILED);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_SSL_ENGINE_NOTFOUND", CURLE_SSL_ENGINE_NOTFOUND);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_SSL_ENGINE_SETFAILED", CURLE_SSL_ENGINE_SETFAILED);
#if 0x072900 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLE_SSL_INVALIDCERTSTATUS", CURLE_SSL_INVALIDCERTSTATUS);
#endif
#if 0x071300 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLE_SSL_ISSUER_ERROR", CURLE_SSL_ISSUER_ERROR);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLE_SSL_PEER_CERTIFICATE", CURLE_SSL_PEER_CERTIFICATE);
#if 0x072700 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLE_SSL_PINNEDPUBKEYNOTMATCH", CURLE_SSL_PINNEDPUBKEYNOTMATCH);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLE_SSL_SHUTDOWN_FAILED", CURLE_SSL_SHUTDOWN_FAILED);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_TELNET_OPTION_SYNTAX", CURLE_TELNET_OPTION_SYNTAX);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_TFTP_ILLEGAL", CURLE_TFTP_ILLEGAL);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_TFTP_NOSUCHUSER", CURLE_TFTP_NOSUCHUSER);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_TFTP_NOTFOUND", CURLE_TFTP_NOTFOUND);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_TFTP_PERM", CURLE_TFTP_PERM);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_TFTP_UNKNOWNID", CURLE_TFTP_UNKNOWNID);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_TOO_MANY_REDIRECTS", CURLE_TOO_MANY_REDIRECTS);
#if 0x071505 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLE_UNKNOWN_OPTION", CURLE_UNKNOWN_OPTION);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLE_UNKNOWN_TELNET_OPTION", CURLE_UNKNOWN_TELNET_OPTION);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_UNSUPPORTED_PROTOCOL", CURLE_UNSUPPORTED_PROTOCOL);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_UPLOAD_FAILED", CURLE_UPLOAD_FAILED);
    luaX_set_field<lua_Integer>(L, -1, "CURLE_URL_MALFORMAT", CURLE_URL_MALFORMAT);
#if 0x071100 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLE_USE_SSL_FAILED", CURLE_USE_SSL_FAILED);
#endif
#if 0x073300 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLE_WEIRD_SERVER_REPLY", CURLE_WEIRD_SERVER_REPLY);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLE_WRITE_ERROR", CURLE_WRITE_ERROR);
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLFILETYPE_DEVICE_BLOCK", CURLFILETYPE_DEVICE_BLOCK);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLFILETYPE_DEVICE_CHAR", CURLFILETYPE_DEVICE_CHAR);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLFILETYPE_DIRECTORY", CURLFILETYPE_DIRECTORY);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLFILETYPE_DOOR", CURLFILETYPE_DOOR);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLFILETYPE_FILE", CURLFILETYPE_FILE);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLFILETYPE_NAMEDPIPE", CURLFILETYPE_NAMEDPIPE);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLFILETYPE_SOCKET", CURLFILETYPE_SOCKET);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLFILETYPE_SYMLINK", CURLFILETYPE_SYMLINK);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLFILETYPE_UNKNOWN", CURLFILETYPE_UNKNOWN);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLFINFOFLAG_KNOWN_FILENAME", CURLFINFOFLAG_KNOWN_FILENAME);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLFINFOFLAG_KNOWN_FILETYPE", CURLFINFOFLAG_KNOWN_FILETYPE);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLFINFOFLAG_KNOWN_GID", CURLFINFOFLAG_KNOWN_GID);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLFINFOFLAG_KNOWN_HLINKCOUNT", CURLFINFOFLAG_KNOWN_HLINKCOUNT);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLFINFOFLAG_KNOWN_PERM", CURLFINFOFLAG_KNOWN_PERM);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLFINFOFLAG_KNOWN_SIZE", CURLFINFOFLAG_KNOWN_SIZE);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLFINFOFLAG_KNOWN_TIME", CURLFINFOFLAG_KNOWN_TIME);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLFINFOFLAG_KNOWN_UID", CURLFINFOFLAG_KNOWN_UID);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLFORM_ARRAY", CURLFORM_ARRAY);
    luaX_set_field<lua_Integer>(L, -1, "CURLFORM_BUFFER", CURLFORM_BUFFER);
    luaX_set_field<lua_Integer>(L, -1, "CURLFORM_BUFFERLENGTH", CURLFORM_BUFFERLENGTH);
    luaX_set_field<lua_Integer>(L, -1, "CURLFORM_BUFFERPTR", CURLFORM_BUFFERPTR);
    luaX_set_field<lua_Integer>(L, -1, "CURLFORM_CONTENTHEADER", CURLFORM_CONTENTHEADER);
#if 0x072e00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLFORM_CONTENTLEN", CURLFORM_CONTENTLEN);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLFORM_CONTENTSLENGTH", CURLFORM_CONTENTSLENGTH);
    luaX_set_field<lua_Integer>(L, -1, "CURLFORM_CONTENTTYPE", CURLFORM_CONTENTTYPE);
    luaX_set_field<lua_Integer>(L, -1, "CURLFORM_COPYCONTENTS", CURLFORM_COPYCONTENTS);
    luaX_set_field<lua_Integer>(L, -1, "CURLFORM_COPYNAME", CURLFORM_COPYNAME);
    luaX_set_field<lua_Integer>(L, -1, "CURLFORM_END", CURLFORM_END);
    luaX_set_field<lua_Integer>(L, -1, "CURLFORM_FILE", CURLFORM_FILE);
    luaX_set_field<lua_Integer>(L, -1, "CURLFORM_FILECONTENT", CURLFORM_FILECONTENT);
    luaX_set_field<lua_Integer>(L, -1, "CURLFORM_FILENAME", CURLFORM_FILENAME);
    luaX_set_field<lua_Integer>(L, -1, "CURLFORM_NAMELENGTH", CURLFORM_NAMELENGTH);
    luaX_set_field<lua_Integer>(L, -1, "CURLFORM_NOTHING", CURLFORM_NOTHING);
    luaX_set_field<lua_Integer>(L, -1, "CURLFORM_PTRCONTENTS", CURLFORM_PTRCONTENTS);
    luaX_set_field<lua_Integer>(L, -1, "CURLFORM_PTRNAME", CURLFORM_PTRNAME);
#if 0x071202 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLFORM_STREAM", CURLFORM_STREAM);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLFTPAUTH_DEFAULT", CURLFTPAUTH_DEFAULT);
    luaX_set_field<lua_Integer>(L, -1, "CURLFTPAUTH_SSL", CURLFTPAUTH_SSL);
    luaX_set_field<lua_Integer>(L, -1, "CURLFTPAUTH_TLS", CURLFTPAUTH_TLS);
    luaX_set_field<lua_Integer>(L, -1, "CURLFTPMETHOD_DEFAULT", CURLFTPMETHOD_DEFAULT);
    luaX_set_field<lua_Integer>(L, -1, "CURLFTPMETHOD_MULTICWD", CURLFTPMETHOD_MULTICWD);
    luaX_set_field<lua_Integer>(L, -1, "CURLFTPMETHOD_NOCWD", CURLFTPMETHOD_NOCWD);
    luaX_set_field<lua_Integer>(L, -1, "CURLFTPMETHOD_SINGLECWD", CURLFTPMETHOD_SINGLECWD);
    luaX_set_field<lua_Integer>(L, -1, "CURLFTPSSL_CCC_ACTIVE", CURLFTPSSL_CCC_ACTIVE);
    luaX_set_field<lua_Integer>(L, -1, "CURLFTPSSL_CCC_NONE", CURLFTPSSL_CCC_NONE);
    luaX_set_field<lua_Integer>(L, -1, "CURLFTPSSL_CCC_PASSIVE", CURLFTPSSL_CCC_PASSIVE);
#if 0x071304 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLFTP_CREATE_DIR", CURLFTP_CREATE_DIR);
#endif
#if 0x071304 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLFTP_CREATE_DIR_NONE", CURLFTP_CREATE_DIR_NONE);
#endif
#if 0x071304 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLFTP_CREATE_DIR_RETRY", CURLFTP_CREATE_DIR_RETRY);
#endif
#if 0x071600 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLGSSAPI_DELEGATION_FLAG", CURLGSSAPI_DELEGATION_FLAG);
#endif
#if 0x071600 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLGSSAPI_DELEGATION_NONE", CURLGSSAPI_DELEGATION_NONE);
#endif
#if 0x071600 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLGSSAPI_DELEGATION_POLICY_FLAG", CURLGSSAPI_DELEGATION_POLICY_FLAG);
#endif
#if 0x072500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLHEADER_SEPARATE", CURLHEADER_SEPARATE);
#endif
#if 0x072500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLHEADER_UNIFIED", CURLHEADER_UNIFIED);
#endif
#if 0x072d00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_ACTIVESOCKET", CURLINFO_ACTIVESOCKET);
#endif
#if 0x071300 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_APPCONNECT_TIME", CURLINFO_APPCONNECT_TIME);
#endif
#if 0x071301 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_CERTINFO", CURLINFO_CERTINFO);
#endif
#if 0x071304 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_CONDITION_UNMET", CURLINFO_CONDITION_UNMET);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_CONNECT_TIME", CURLINFO_CONNECT_TIME);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_CONTENT_LENGTH_DOWNLOAD", CURLINFO_CONTENT_LENGTH_DOWNLOAD);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_CONTENT_LENGTH_UPLOAD", CURLINFO_CONTENT_LENGTH_UPLOAD);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_CONTENT_TYPE", CURLINFO_CONTENT_TYPE);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_COOKIELIST", CURLINFO_COOKIELIST);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_DATA_IN", CURLINFO_DATA_IN);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_DATA_OUT", CURLINFO_DATA_OUT);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_DOUBLE", CURLINFO_DOUBLE);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_EFFECTIVE_URL", CURLINFO_EFFECTIVE_URL);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_END", CURLINFO_END);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_FILETIME", CURLINFO_FILETIME);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_FTP_ENTRY_PATH", CURLINFO_FTP_ENTRY_PATH);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_HEADER_IN", CURLINFO_HEADER_IN);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_HEADER_OUT", CURLINFO_HEADER_OUT);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_HEADER_SIZE", CURLINFO_HEADER_SIZE);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_HTTPAUTH_AVAIL", CURLINFO_HTTPAUTH_AVAIL);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_HTTP_CONNECTCODE", CURLINFO_HTTP_CONNECTCODE);
#if 0x073200 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_HTTP_VERSION", CURLINFO_HTTP_VERSION);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_LASTONE", CURLINFO_LASTONE);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_LASTSOCKET", CURLINFO_LASTSOCKET);
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_LOCAL_IP", CURLINFO_LOCAL_IP);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_LOCAL_PORT", CURLINFO_LOCAL_PORT);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_LONG", CURLINFO_LONG);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_MASK", CURLINFO_MASK);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_NAMELOOKUP_TIME", CURLINFO_NAMELOOKUP_TIME);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_NONE", CURLINFO_NONE);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_NUM_CONNECTS", CURLINFO_NUM_CONNECTS);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_OS_ERRNO", CURLINFO_OS_ERRNO);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_PRETRANSFER_TIME", CURLINFO_PRETRANSFER_TIME);
#if 0x071300 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_PRIMARY_IP", CURLINFO_PRIMARY_IP);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_PRIMARY_PORT", CURLINFO_PRIMARY_PORT);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_PRIVATE", CURLINFO_PRIVATE);
#if 0x073400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_PROTOCOL", CURLINFO_PROTOCOL);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_PROXYAUTH_AVAIL", CURLINFO_PROXYAUTH_AVAIL);
#if 0x073400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_PROXY_SSL_VERIFYRESULT", CURLINFO_PROXY_SSL_VERIFYRESULT);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_REDIRECT_COUNT", CURLINFO_REDIRECT_COUNT);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_REDIRECT_TIME", CURLINFO_REDIRECT_TIME);
#if 0x071202 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_REDIRECT_URL", CURLINFO_REDIRECT_URL);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_REQUEST_SIZE", CURLINFO_REQUEST_SIZE);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_RESPONSE_CODE", CURLINFO_RESPONSE_CODE);
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_RTSP_CLIENT_CSEQ", CURLINFO_RTSP_CLIENT_CSEQ);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_RTSP_CSEQ_RECV", CURLINFO_RTSP_CSEQ_RECV);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_RTSP_SERVER_CSEQ", CURLINFO_RTSP_SERVER_CSEQ);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_RTSP_SESSION_ID", CURLINFO_RTSP_SESSION_ID);
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_SCHEME", CURLINFO_SCHEME);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_SIZE_DOWNLOAD", CURLINFO_SIZE_DOWNLOAD);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_SIZE_UPLOAD", CURLINFO_SIZE_UPLOAD);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_SLIST", CURLINFO_SLIST);
#if 0x072d00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_SOCKET", CURLINFO_SOCKET);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_SPEED_DOWNLOAD", CURLINFO_SPEED_DOWNLOAD);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_SPEED_UPLOAD", CURLINFO_SPEED_UPLOAD);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_SSL_DATA_IN", CURLINFO_SSL_DATA_IN);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_SSL_DATA_OUT", CURLINFO_SSL_DATA_OUT);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_SSL_ENGINES", CURLINFO_SSL_ENGINES);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_SSL_VERIFYRESULT", CURLINFO_SSL_VERIFYRESULT);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_STARTTRANSFER_TIME", CURLINFO_STARTTRANSFER_TIME);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_STRING", CURLINFO_STRING);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_TEXT", CURLINFO_TEXT);
#if 0x072200 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_TLS_SESSION", CURLINFO_TLS_SESSION);
#endif
#if 0x073000 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_TLS_SSL_PTR", CURLINFO_TLS_SSL_PTR);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_TOTAL_TIME", CURLINFO_TOTAL_TIME);
    luaX_set_field<lua_Integer>(L, -1, "CURLINFO_TYPEMASK", CURLINFO_TYPEMASK);
    luaX_set_field<lua_Integer>(L, -1, "CURLIOCMD_NOP", CURLIOCMD_NOP);
    luaX_set_field<lua_Integer>(L, -1, "CURLIOCMD_RESTARTREAD", CURLIOCMD_RESTARTREAD);
    luaX_set_field<lua_Integer>(L, -1, "CURLIOE_FAILRESTART", CURLIOE_FAILRESTART);
    luaX_set_field<lua_Integer>(L, -1, "CURLIOE_OK", CURLIOE_OK);
    luaX_set_field<lua_Integer>(L, -1, "CURLIOE_UNKNOWNCMD", CURLIOE_UNKNOWNCMD);
#if 0x071306 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLKHMATCH_MISMATCH", CURLKHMATCH_MISMATCH);
#endif
#if 0x071306 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLKHMATCH_MISSING", CURLKHMATCH_MISSING);
#endif
#if 0x071306 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLKHMATCH_OK", CURLKHMATCH_OK);
#endif
#if 0x071306 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLKHSTAT_DEFER", CURLKHSTAT_DEFER);
#endif
#if 0x071306 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLKHSTAT_FINE", CURLKHSTAT_FINE);
#endif
#if 0x071306 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLKHSTAT_FINE_ADD_TO_FILE", CURLKHSTAT_FINE_ADD_TO_FILE);
#endif
#if 0x071306 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLKHSTAT_REJECT", CURLKHSTAT_REJECT);
#endif
#if 0x071e00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLMOPT_CHUNK_LENGTH_PENALTY_SIZE", CURLMOPT_CHUNK_LENGTH_PENALTY_SIZE);
#endif
#if 0x071e00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLMOPT_CONTENT_LENGTH_PENALTY_SIZE", CURLMOPT_CONTENT_LENGTH_PENALTY_SIZE);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLMOPT_MAXCONNECTS", CURLMOPT_MAXCONNECTS);
#if 0x071e00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLMOPT_MAX_HOST_CONNECTIONS", CURLMOPT_MAX_HOST_CONNECTIONS);
#endif
#if 0x071e00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLMOPT_MAX_PIPELINE_LENGTH", CURLMOPT_MAX_PIPELINE_LENGTH);
#endif
#if 0x071e00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLMOPT_MAX_TOTAL_CONNECTIONS", CURLMOPT_MAX_TOTAL_CONNECTIONS);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLMOPT_PIPELINING", CURLMOPT_PIPELINING);
#if 0x071e00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLMOPT_PIPELINING_SERVER_BL", CURLMOPT_PIPELINING_SERVER_BL);
#endif
#if 0x071e00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLMOPT_PIPELINING_SITE_BL", CURLMOPT_PIPELINING_SITE_BL);
#endif
#if 0x072c00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLMOPT_PUSHDATA", CURLMOPT_PUSHDATA);
#endif
#if 0x072c00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLMOPT_PUSHFUNCTION", CURLMOPT_PUSHFUNCTION);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLMOPT_SOCKETDATA", CURLMOPT_SOCKETDATA);
    luaX_set_field<lua_Integer>(L, -1, "CURLMOPT_SOCKETFUNCTION", CURLMOPT_SOCKETFUNCTION);
    luaX_set_field<lua_Integer>(L, -1, "CURLMOPT_TIMERDATA", CURLMOPT_TIMERDATA);
    luaX_set_field<lua_Integer>(L, -1, "CURLMOPT_TIMERFUNCTION", CURLMOPT_TIMERFUNCTION);
    luaX_set_field<lua_Integer>(L, -1, "CURLMSG_DONE", CURLMSG_DONE);
    luaX_set_field<lua_Integer>(L, -1, "CURLMSG_NONE", CURLMSG_NONE);
#if 0x072001 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLM_ADDED_ALREADY", CURLM_ADDED_ALREADY);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLM_BAD_EASY_HANDLE", CURLM_BAD_EASY_HANDLE);
    luaX_set_field<lua_Integer>(L, -1, "CURLM_BAD_HANDLE", CURLM_BAD_HANDLE);
    luaX_set_field<lua_Integer>(L, -1, "CURLM_BAD_SOCKET", CURLM_BAD_SOCKET);
    luaX_set_field<lua_Integer>(L, -1, "CURLM_CALL_MULTI_PERFORM", CURLM_CALL_MULTI_PERFORM);
    luaX_set_field<lua_Integer>(L, -1, "CURLM_CALL_MULTI_SOCKET", CURLM_CALL_MULTI_SOCKET);
    luaX_set_field<lua_Integer>(L, -1, "CURLM_INTERNAL_ERROR", CURLM_INTERNAL_ERROR);
    luaX_set_field<lua_Integer>(L, -1, "CURLM_OK", CURLM_OK);
    luaX_set_field<lua_Integer>(L, -1, "CURLM_OUT_OF_MEMORY", CURLM_OUT_OF_MEMORY);
    luaX_set_field<lua_Integer>(L, -1, "CURLM_UNKNOWN_OPTION", CURLM_UNKNOWN_OPTION);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPTTYPE_FUNCTIONPOINT", CURLOPTTYPE_FUNCTIONPOINT);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPTTYPE_LONG", CURLOPTTYPE_LONG);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPTTYPE_OBJECTPOINT", CURLOPTTYPE_OBJECTPOINT);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPTTYPE_OFF_T", CURLOPTTYPE_OFF_T);
#if 0x072e00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPTTYPE_STRINGPOINT", CURLOPTTYPE_STRINGPOINT);
#endif
#if 0x071800 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_ACCEPTTIMEOUT_MS", CURLOPT_ACCEPTTIMEOUT_MS);
#endif
#if 0x071506 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_ACCEPT_ENCODING", CURLOPT_ACCEPT_ENCODING);
#endif
#if 0x071300 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_ADDRESS_SCOPE", CURLOPT_ADDRESS_SCOPE);
#endif
#if 0x071100 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_APPEND", CURLOPT_APPEND);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_AUTOREFERER", CURLOPT_AUTOREFERER);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_BUFFERSIZE", CURLOPT_BUFFERSIZE);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_CAINFO", CURLOPT_CAINFO);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_CAPATH", CURLOPT_CAPATH);
#if 0x071301 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_CERTINFO", CURLOPT_CERTINFO);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_CHUNK_BGN_FUNCTION", CURLOPT_CHUNK_BGN_FUNCTION);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_CHUNK_DATA", CURLOPT_CHUNK_DATA);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_CHUNK_END_FUNCTION", CURLOPT_CHUNK_END_FUNCTION);
#endif
#if 0x071507 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_CLOSESOCKETDATA", CURLOPT_CLOSESOCKETDATA);
#endif
#if 0x071507 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_CLOSESOCKETFUNCTION", CURLOPT_CLOSESOCKETFUNCTION);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_CONNECTTIMEOUT", CURLOPT_CONNECTTIMEOUT);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_CONNECTTIMEOUT_MS", CURLOPT_CONNECTTIMEOUT_MS);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_CONNECT_ONLY", CURLOPT_CONNECT_ONLY);
#if 0x073100 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_CONNECT_TO", CURLOPT_CONNECT_TO);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_CONV_FROM_NETWORK_FUNCTION", CURLOPT_CONV_FROM_NETWORK_FUNCTION);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_CONV_FROM_UTF8_FUNCTION", CURLOPT_CONV_FROM_UTF8_FUNCTION);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_CONV_TO_NETWORK_FUNCTION", CURLOPT_CONV_TO_NETWORK_FUNCTION);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_COOKIE", CURLOPT_COOKIE);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_COOKIEFILE", CURLOPT_COOKIEFILE);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_COOKIEJAR", CURLOPT_COOKIEJAR);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_COOKIELIST", CURLOPT_COOKIELIST);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_COOKIESESSION", CURLOPT_COOKIESESSION);
#if 0x071101 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_COPYPOSTFIELDS", CURLOPT_COPYPOSTFIELDS);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_CRLF", CURLOPT_CRLF);
#if 0x071300 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_CRLFILE", CURLOPT_CRLFILE);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_CUSTOMREQUEST", CURLOPT_CUSTOMREQUEST);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_DEBUGDATA", CURLOPT_DEBUGDATA);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_DEBUGFUNCTION", CURLOPT_DEBUGFUNCTION);
#if 0x072d00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_DEFAULT_PROTOCOL", CURLOPT_DEFAULT_PROTOCOL);
#endif
#if 0x071100 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_DIRLISTONLY", CURLOPT_DIRLISTONLY);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_DNS_CACHE_TIMEOUT", CURLOPT_DNS_CACHE_TIMEOUT);
#if 0x072100 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_DNS_INTERFACE", CURLOPT_DNS_INTERFACE);
#endif
#if 0x072100 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_DNS_LOCAL_IP4", CURLOPT_DNS_LOCAL_IP4);
#endif
#if 0x072100 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_DNS_LOCAL_IP6", CURLOPT_DNS_LOCAL_IP6);
#endif
#if 0x071800 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_DNS_SERVERS", CURLOPT_DNS_SERVERS);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_EGDSOCKET", CURLOPT_EGDSOCKET);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_ENCODING", CURLOPT_ENCODING);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_ERRORBUFFER", CURLOPT_ERRORBUFFER);
#if 0x072400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_EXPECT_100_TIMEOUT_MS", CURLOPT_EXPECT_100_TIMEOUT_MS);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_FAILONERROR", CURLOPT_FAILONERROR);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_FILETIME", CURLOPT_FILETIME);
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_FNMATCH_DATA", CURLOPT_FNMATCH_DATA);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_FNMATCH_FUNCTION", CURLOPT_FNMATCH_FUNCTION);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_FOLLOWLOCATION", CURLOPT_FOLLOWLOCATION);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_FORBID_REUSE", CURLOPT_FORBID_REUSE);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_FRESH_CONNECT", CURLOPT_FRESH_CONNECT);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_FTPPORT", CURLOPT_FTPPORT);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_FTPSSLAUTH", CURLOPT_FTPSSLAUTH);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_FTP_ACCOUNT", CURLOPT_FTP_ACCOUNT);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_FTP_ALTERNATIVE_TO_USER", CURLOPT_FTP_ALTERNATIVE_TO_USER);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_FTP_CREATE_MISSING_DIRS", CURLOPT_FTP_CREATE_MISSING_DIRS);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_FTP_FILEMETHOD", CURLOPT_FTP_FILEMETHOD);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_FTP_RESPONSE_TIMEOUT", CURLOPT_FTP_RESPONSE_TIMEOUT);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_FTP_SKIP_PASV_IP", CURLOPT_FTP_SKIP_PASV_IP);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_FTP_SSL_CCC", CURLOPT_FTP_SSL_CCC);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_FTP_USE_EPRT", CURLOPT_FTP_USE_EPRT);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_FTP_USE_EPSV", CURLOPT_FTP_USE_EPSV);
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_FTP_USE_PRET", CURLOPT_FTP_USE_PRET);
#endif
#if 0x071600 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_GSSAPI_DELEGATION", CURLOPT_GSSAPI_DELEGATION);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_HEADER", CURLOPT_HEADER);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_HEADERDATA", CURLOPT_HEADERDATA);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_HEADERFUNCTION", CURLOPT_HEADERFUNCTION);
#if 0x072500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_HEADEROPT", CURLOPT_HEADEROPT);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_HTTP200ALIASES", CURLOPT_HTTP200ALIASES);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_HTTPAUTH", CURLOPT_HTTPAUTH);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_HTTPGET", CURLOPT_HTTPGET);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_HTTPHEADER", CURLOPT_HTTPHEADER);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_HTTPPOST", CURLOPT_HTTPPOST);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_HTTPPROXYTUNNEL", CURLOPT_HTTPPROXYTUNNEL);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_HTTP_CONTENT_DECODING", CURLOPT_HTTP_CONTENT_DECODING);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_HTTP_TRANSFER_DECODING", CURLOPT_HTTP_TRANSFER_DECODING);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_HTTP_VERSION", CURLOPT_HTTP_VERSION);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_IGNORE_CONTENT_LENGTH", CURLOPT_IGNORE_CONTENT_LENGTH);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_INFILESIZE", CURLOPT_INFILESIZE);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_INFILESIZE_LARGE", CURLOPT_INFILESIZE_LARGE);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_INTERFACE", CURLOPT_INTERFACE);
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_INTERLEAVEDATA", CURLOPT_INTERLEAVEDATA);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_INTERLEAVEFUNCTION", CURLOPT_INTERLEAVEFUNCTION);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_IOCTLDATA", CURLOPT_IOCTLDATA);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_IOCTLFUNCTION", CURLOPT_IOCTLFUNCTION);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_IPRESOLVE", CURLOPT_IPRESOLVE);
#if 0x071300 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_ISSUERCERT", CURLOPT_ISSUERCERT);
#endif
#if 0x071100 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_KEYPASSWD", CURLOPT_KEYPASSWD);
#endif
#if 0x073300 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_KEEP_SENDING_ON_ERROR", CURLOPT_KEEP_SENDING_ON_ERROR);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_KRBLEVEL", CURLOPT_KRBLEVEL);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_LOCALPORT", CURLOPT_LOCALPORT);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_LOCALPORTRANGE", CURLOPT_LOCALPORTRANGE);
#if 0x072200 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_LOGIN_OPTIONS", CURLOPT_LOGIN_OPTIONS);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_LOW_SPEED_LIMIT", CURLOPT_LOW_SPEED_LIMIT);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_LOW_SPEED_TIME", CURLOPT_LOW_SPEED_TIME);
#if 0x071900 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_MAIL_AUTH", CURLOPT_MAIL_AUTH);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_MAIL_FROM", CURLOPT_MAIL_FROM);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_MAIL_RCPT", CURLOPT_MAIL_RCPT);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_MAXCONNECTS", CURLOPT_MAXCONNECTS);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_MAXFILESIZE", CURLOPT_MAXFILESIZE);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_MAXFILESIZE_LARGE", CURLOPT_MAXFILESIZE_LARGE);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_MAXREDIRS", CURLOPT_MAXREDIRS);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_MAX_RECV_SPEED_LARGE", CURLOPT_MAX_RECV_SPEED_LARGE);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_MAX_SEND_SPEED_LARGE", CURLOPT_MAX_SEND_SPEED_LARGE);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_NETRC", CURLOPT_NETRC);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_NETRC_FILE", CURLOPT_NETRC_FILE);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_NEW_DIRECTORY_PERMS", CURLOPT_NEW_DIRECTORY_PERMS);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_NEW_FILE_PERMS", CURLOPT_NEW_FILE_PERMS);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_NOBODY", CURLOPT_NOBODY);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_NOPROGRESS", CURLOPT_NOPROGRESS);
#if 0x071304 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_NOPROXY", CURLOPT_NOPROXY);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_NOSIGNAL", CURLOPT_NOSIGNAL);
#if 0x071101 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_OPENSOCKETDATA", CURLOPT_OPENSOCKETDATA);
#endif
#if 0x071101 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_OPENSOCKETFUNCTION", CURLOPT_OPENSOCKETFUNCTION);
#endif
#if 0x071301 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PASSWORD", CURLOPT_PASSWORD);
#endif
#if 0x072a00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PATH_AS_IS", CURLOPT_PATH_AS_IS);
#endif
#if 0x072700 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PINNEDPUBLICKEY", CURLOPT_PINNEDPUBLICKEY);
#endif
#if 0x072b00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PIPEWAIT", CURLOPT_PIPEWAIT);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PORT", CURLOPT_PORT);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_POST", CURLOPT_POST);
#if 0x071101 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_POST301", CURLOPT_POST301);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_POSTFIELDS", CURLOPT_POSTFIELDS);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_POSTFIELDSIZE", CURLOPT_POSTFIELDSIZE);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_POSTFIELDSIZE_LARGE", CURLOPT_POSTFIELDSIZE_LARGE);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_POSTQUOTE", CURLOPT_POSTQUOTE);
#if 0x071301 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_POSTREDIR", CURLOPT_POSTREDIR);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PREQUOTE", CURLOPT_PREQUOTE);
#if 0x073400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PRE_PROXY", CURLOPT_PRE_PROXY);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PRIVATE", CURLOPT_PRIVATE);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROGRESSDATA", CURLOPT_PROGRESSDATA);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROGRESSFUNCTION", CURLOPT_PROGRESSFUNCTION);
#if 0x071304 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROTOCOLS", CURLOPT_PROTOCOLS);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROXY", CURLOPT_PROXY);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROXYAUTH", CURLOPT_PROXYAUTH);
#if 0x072500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROXYHEADER", CURLOPT_PROXYHEADER);
#endif
#if 0x071301 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROXYPASSWORD", CURLOPT_PROXYPASSWORD);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROXYPORT", CURLOPT_PROXYPORT);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROXYTYPE", CURLOPT_PROXYTYPE);
#if 0x071301 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROXYUSERNAME", CURLOPT_PROXYUSERNAME);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROXYUSERPWD", CURLOPT_PROXYUSERPWD);
#if 0x073400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROXY_CAINFO", CURLOPT_PROXY_CAINFO);
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROXY_CAPATH", CURLOPT_PROXY_CAPATH);
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROXY_CRLFILE", CURLOPT_PROXY_CRLFILE);
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROXY_KEYPASSWD", CURLOPT_PROXY_KEYPASSWD);
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROXY_PINNEDPUBLICKEY", CURLOPT_PROXY_PINNEDPUBLICKEY);
#endif
#if 0x072b00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROXY_SERVICE_NAME", CURLOPT_PROXY_SERVICE_NAME);
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROXY_SSLCERT", CURLOPT_PROXY_SSLCERT);
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROXY_SSLCERTTYPE", CURLOPT_PROXY_SSLCERTTYPE);
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROXY_SSLKEY", CURLOPT_PROXY_SSLKEY);
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROXY_SSLKEYTYPE", CURLOPT_PROXY_SSLKEYTYPE);
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROXY_SSLVERSION", CURLOPT_PROXY_SSLVERSION);
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROXY_SSL_CIPHER_LIST", CURLOPT_PROXY_SSL_CIPHER_LIST);
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROXY_SSL_OPTIONS", CURLOPT_PROXY_SSL_OPTIONS);
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROXY_SSL_VERIFYHOST", CURLOPT_PROXY_SSL_VERIFYHOST);
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROXY_SSL_VERIFYPEER", CURLOPT_PROXY_SSL_VERIFYPEER);
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROXY_TLSAUTH_PASSWORD", CURLOPT_PROXY_TLSAUTH_PASSWORD);
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROXY_TLSAUTH_TYPE", CURLOPT_PROXY_TLSAUTH_TYPE);
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROXY_TLSAUTH_USERNAME", CURLOPT_PROXY_TLSAUTH_USERNAME);
#endif
#if 0x071200 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PROXY_TRANSFER_MODE", CURLOPT_PROXY_TRANSFER_MODE);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_PUT", CURLOPT_PUT);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_QUOTE", CURLOPT_QUOTE);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_RANDOM_FILE", CURLOPT_RANDOM_FILE);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_RANGE", CURLOPT_RANGE);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_READDATA", CURLOPT_READDATA);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_READFUNCTION", CURLOPT_READFUNCTION);
#if 0x071304 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_REDIR_PROTOCOLS", CURLOPT_REDIR_PROTOCOLS);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_REFERER", CURLOPT_REFERER);
#if 0x071503 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_RESOLVE", CURLOPT_RESOLVE);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_RESUME_FROM", CURLOPT_RESUME_FROM);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_RESUME_FROM_LARGE", CURLOPT_RESUME_FROM_LARGE);
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_RTSPHEADER", CURLOPT_RTSPHEADER);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_RTSP_CLIENT_CSEQ", CURLOPT_RTSP_CLIENT_CSEQ);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_RTSP_REQUEST", CURLOPT_RTSP_REQUEST);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_RTSP_SERVER_CSEQ", CURLOPT_RTSP_SERVER_CSEQ);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_RTSP_SESSION_ID", CURLOPT_RTSP_SESSION_ID);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_RTSP_STREAM_URI", CURLOPT_RTSP_STREAM_URI);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_RTSP_TRANSPORT", CURLOPT_RTSP_TRANSPORT);
#endif
#if 0x071f00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SASL_IR", CURLOPT_SASL_IR);
#endif
#if 0x071200 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SEEKDATA", CURLOPT_SEEKDATA);
#endif
#if 0x071200 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SEEKFUNCTION", CURLOPT_SEEKFUNCTION);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SERVER_RESPONSE_TIMEOUT", CURLOPT_SERVER_RESPONSE_TIMEOUT);
#endif
#if 0x072b00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SERVICE_NAME", CURLOPT_SERVICE_NAME);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SHARE", CURLOPT_SHARE);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SOCKOPTDATA", CURLOPT_SOCKOPTDATA);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SOCKOPTFUNCTION", CURLOPT_SOCKOPTFUNCTION);
#if 0x071304 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SOCKS5_GSSAPI_NEC", CURLOPT_SOCKS5_GSSAPI_NEC);
#endif
#if 0x071304 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SOCKS5_GSSAPI_SERVICE", CURLOPT_SOCKS5_GSSAPI_SERVICE);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SSH_AUTH_TYPES", CURLOPT_SSH_AUTH_TYPES);
#if 0x071101 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SSH_HOST_PUBLIC_KEY_MD5", CURLOPT_SSH_HOST_PUBLIC_KEY_MD5);
#endif
#if 0x071306 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SSH_KEYDATA", CURLOPT_SSH_KEYDATA);
#endif
#if 0x071306 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SSH_KEYFUNCTION", CURLOPT_SSH_KEYFUNCTION);
#endif
#if 0x071306 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SSH_KNOWNHOSTS", CURLOPT_SSH_KNOWNHOSTS);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SSH_PRIVATE_KEYFILE", CURLOPT_SSH_PRIVATE_KEYFILE);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SSH_PUBLIC_KEYFILE", CURLOPT_SSH_PUBLIC_KEYFILE);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SSLCERT", CURLOPT_SSLCERT);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SSLCERTTYPE", CURLOPT_SSLCERTTYPE);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SSLENGINE", CURLOPT_SSLENGINE);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SSLENGINE_DEFAULT", CURLOPT_SSLENGINE_DEFAULT);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SSLKEY", CURLOPT_SSLKEY);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SSLKEYTYPE", CURLOPT_SSLKEYTYPE);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SSLVERSION", CURLOPT_SSLVERSION);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SSL_CIPHER_LIST", CURLOPT_SSL_CIPHER_LIST);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SSL_CTX_DATA", CURLOPT_SSL_CTX_DATA);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SSL_CTX_FUNCTION", CURLOPT_SSL_CTX_FUNCTION);
#if 0x072400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SSL_ENABLE_ALPN", CURLOPT_SSL_ENABLE_ALPN);
#endif
#if 0x072400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SSL_ENABLE_NPN", CURLOPT_SSL_ENABLE_NPN);
#endif
#if 0x072a00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SSL_FALSESTART", CURLOPT_SSL_FALSESTART);
#endif
#if 0x071900 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SSL_OPTIONS", CURLOPT_SSL_OPTIONS);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SSL_SESSIONID_CACHE", CURLOPT_SSL_SESSIONID_CACHE);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SSL_VERIFYHOST", CURLOPT_SSL_VERIFYHOST);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SSL_VERIFYPEER", CURLOPT_SSL_VERIFYPEER);
#if 0x072900 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_SSL_VERIFYSTATUS", CURLOPT_SSL_VERIFYSTATUS);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_STDERR", CURLOPT_STDERR);
#if 0x072e00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_STREAM_DEPENDS", CURLOPT_STREAM_DEPENDS);
#endif
#if 0x072e00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_STREAM_DEPENDS_E", CURLOPT_STREAM_DEPENDS_E);
#endif
#if 0x072e00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_STREAM_WEIGHT", CURLOPT_STREAM_WEIGHT);
#endif
#if 0x071900 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_TCP_KEEPALIVE", CURLOPT_TCP_KEEPALIVE);
#endif
#if 0x071900 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_TCP_KEEPIDLE", CURLOPT_TCP_KEEPIDLE);
#endif
#if 0x071900 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_TCP_KEEPINTVL", CURLOPT_TCP_KEEPINTVL);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_TCP_NODELAY", CURLOPT_TCP_NODELAY);
#if 0x073100 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_TCP_FASTOPEN", CURLOPT_TCP_FASTOPEN);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_TELNETOPTIONS", CURLOPT_TELNETOPTIONS);
#if 0x071304 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_TFTP_BLKSIZE", CURLOPT_TFTP_BLKSIZE);
#endif
#if 0x073000 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_TFTP_NO_OPTIONS", CURLOPT_TFTP_NO_OPTIONS);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_TIMECONDITION", CURLOPT_TIMECONDITION);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_TIMEOUT", CURLOPT_TIMEOUT);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_TIMEOUT_MS", CURLOPT_TIMEOUT_MS);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_TIMEVALUE", CURLOPT_TIMEVALUE);
#if 0x071504 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_TLSAUTH_PASSWORD", CURLOPT_TLSAUTH_PASSWORD);
#endif
#if 0x071504 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_TLSAUTH_TYPE", CURLOPT_TLSAUTH_TYPE);
#endif
#if 0x071504 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_TLSAUTH_USERNAME", CURLOPT_TLSAUTH_USERNAME);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_TRANSFERTEXT", CURLOPT_TRANSFERTEXT);
#if 0x071506 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_TRANSFER_ENCODING", CURLOPT_TRANSFER_ENCODING);
#endif
#if 0x072800 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_UNIX_SOCKET_PATH", CURLOPT_UNIX_SOCKET_PATH);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_UNRESTRICTED_AUTH", CURLOPT_UNRESTRICTED_AUTH);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_UPLOAD", CURLOPT_UPLOAD);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_URL", CURLOPT_URL);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_USERAGENT", CURLOPT_USERAGENT);
#if 0x071301 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_USERNAME", CURLOPT_USERNAME);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_USERPWD", CURLOPT_USERPWD);
#if 0x071100 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_USE_SSL", CURLOPT_USE_SSL);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_VERBOSE", CURLOPT_VERBOSE);
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_WILDCARDMATCH", CURLOPT_WILDCARDMATCH);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_WRITEDATA", CURLOPT_WRITEDATA);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_WRITEFUNCTION", CURLOPT_WRITEFUNCTION);
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_WRITEHEADER", CURLOPT_WRITEHEADER);
#if 0x072000 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_XFERINFODATA", CURLOPT_XFERINFODATA);
#endif
#if 0x072000 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_XFERINFOFUNCTION", CURLOPT_XFERINFOFUNCTION);
#endif
#if 0x072100 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLOPT_XOAUTH2_BEARER", CURLOPT_XOAUTH2_BEARER);
#endif
#if 0x071200 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPAUSE_ALL", CURLPAUSE_ALL);
#endif
#if 0x071200 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPAUSE_CONT", CURLPAUSE_CONT);
#endif
#if 0x071200 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPAUSE_RECV", CURLPAUSE_RECV);
#endif
#if 0x071200 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPAUSE_RECV_CONT", CURLPAUSE_RECV_CONT);
#endif
#if 0x071200 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPAUSE_SEND", CURLPAUSE_SEND);
#endif
#if 0x071200 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPAUSE_SEND_CONT", CURLPAUSE_SEND_CONT);
#endif
#if 0x072b00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPIPE_HTTP1", CURLPIPE_HTTP1);
#endif
#if 0x072b00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPIPE_MULTIPLEX", CURLPIPE_MULTIPLEX);
#endif
#if 0x072b00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPIPE_NOTHING", CURLPIPE_NOTHING);
#endif
#if 0x071304 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROTO_ALL", CURLPROTO_ALL);
#endif
#if 0x071304 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROTO_DICT", CURLPROTO_DICT);
#endif
#if 0x071304 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROTO_FILE", CURLPROTO_FILE);
#endif
#if 0x071304 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROTO_FTP", CURLPROTO_FTP);
#endif
#if 0x071304 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROTO_FTPS", CURLPROTO_FTPS);
#endif
#if 0x071502 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROTO_GOPHER", CURLPROTO_GOPHER);
#endif
#if 0x071304 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROTO_HTTP", CURLPROTO_HTTP);
#endif
#if 0x071304 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROTO_HTTPS", CURLPROTO_HTTPS);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROTO_IMAP", CURLPROTO_IMAP);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROTO_IMAPS", CURLPROTO_IMAPS);
#endif
#if 0x071304 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROTO_LDAP", CURLPROTO_LDAP);
#endif
#if 0x071304 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROTO_LDAPS", CURLPROTO_LDAPS);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROTO_POP3", CURLPROTO_POP3);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROTO_POP3S", CURLPROTO_POP3S);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROTO_RTMP", CURLPROTO_RTMP);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROTO_RTMPE", CURLPROTO_RTMPE);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROTO_RTMPS", CURLPROTO_RTMPS);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROTO_RTMPT", CURLPROTO_RTMPT);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROTO_RTMPTE", CURLPROTO_RTMPTE);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROTO_RTMPTS", CURLPROTO_RTMPTS);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROTO_RTSP", CURLPROTO_RTSP);
#endif
#if 0x071304 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROTO_SCP", CURLPROTO_SCP);
#endif
#if 0x071304 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROTO_SFTP", CURLPROTO_SFTP);
#endif
#if 0x072800 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROTO_SMB", CURLPROTO_SMB);
#endif
#if 0x072800 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROTO_SMBS", CURLPROTO_SMBS);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROTO_SMTP", CURLPROTO_SMTP);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROTO_SMTPS", CURLPROTO_SMTPS);
#endif
#if 0x071304 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROTO_TELNET", CURLPROTO_TELNET);
#endif
#if 0x071304 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROTO_TFTP", CURLPROTO_TFTP);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLPROXY_HTTP", CURLPROXY_HTTP);
#if 0x071304 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROXY_HTTP_1_0", CURLPROXY_HTTP_1_0);
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROXY_HTTPS", CURLPROXY_HTTPS);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLPROXY_SOCKS4", CURLPROXY_SOCKS4);
#if 0x071200 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROXY_SOCKS4A", CURLPROXY_SOCKS4A);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLPROXY_SOCKS5", CURLPROXY_SOCKS5);
#if 0x071200 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLPROXY_SOCKS5_HOSTNAME", CURLPROXY_SOCKS5_HOSTNAME);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLSHE_BAD_OPTION", CURLSHE_BAD_OPTION);
    luaX_set_field<lua_Integer>(L, -1, "CURLSHE_INVALID", CURLSHE_INVALID);
    luaX_set_field<lua_Integer>(L, -1, "CURLSHE_IN_USE", CURLSHE_IN_USE);
    luaX_set_field<lua_Integer>(L, -1, "CURLSHE_NOMEM", CURLSHE_NOMEM);
#if 0x071700 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLSHE_NOT_BUILT_IN", CURLSHE_NOT_BUILT_IN);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLSHE_OK", CURLSHE_OK);
    luaX_set_field<lua_Integer>(L, -1, "CURLSHOPT_LOCKFUNC", CURLSHOPT_LOCKFUNC);
    luaX_set_field<lua_Integer>(L, -1, "CURLSHOPT_NONE", CURLSHOPT_NONE);
    luaX_set_field<lua_Integer>(L, -1, "CURLSHOPT_SHARE", CURLSHOPT_SHARE);
    luaX_set_field<lua_Integer>(L, -1, "CURLSHOPT_UNLOCKFUNC", CURLSHOPT_UNLOCKFUNC);
    luaX_set_field<lua_Integer>(L, -1, "CURLSHOPT_UNSHARE", CURLSHOPT_UNSHARE);
    luaX_set_field<lua_Integer>(L, -1, "CURLSHOPT_USERDATA", CURLSHOPT_USERDATA);
#if 0x071c00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLSOCKTYPE_ACCEPT", CURLSOCKTYPE_ACCEPT);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLSOCKTYPE_IPCXN", CURLSOCKTYPE_IPCXN);
#if 0x071c00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLSSH_AUTH_AGENT", CURLSSH_AUTH_AGENT);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLSSH_AUTH_ANY", CURLSSH_AUTH_ANY);
    luaX_set_field<lua_Integer>(L, -1, "CURLSSH_AUTH_DEFAULT", CURLSSH_AUTH_DEFAULT);
    luaX_set_field<lua_Integer>(L, -1, "CURLSSH_AUTH_HOST", CURLSSH_AUTH_HOST);
    luaX_set_field<lua_Integer>(L, -1, "CURLSSH_AUTH_KEYBOARD", CURLSSH_AUTH_KEYBOARD);
    luaX_set_field<lua_Integer>(L, -1, "CURLSSH_AUTH_NONE", CURLSSH_AUTH_NONE);
    luaX_set_field<lua_Integer>(L, -1, "CURLSSH_AUTH_PASSWORD", CURLSSH_AUTH_PASSWORD);
    luaX_set_field<lua_Integer>(L, -1, "CURLSSH_AUTH_PUBLICKEY", CURLSSH_AUTH_PUBLICKEY);
#if 0x072600 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLSSLBACKEND_AXTLS", CURLSSLBACKEND_AXTLS);
#endif
#if 0x073100 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLSSLBACKEND_BORINGSSL", CURLSSLBACKEND_BORINGSSL);
#endif
#if 0x072200 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLSSLBACKEND_CYASSL", CURLSSLBACKEND_CYASSL);
#endif
#if 0x072200 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLSSLBACKEND_DARWINSSL", CURLSSLBACKEND_DARWINSSL);
#endif
#if 0x072200 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLSSLBACKEND_GNUTLS", CURLSSLBACKEND_GNUTLS);
#endif
#if 0x072200 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLSSLBACKEND_GSKIT", CURLSSLBACKEND_GSKIT);
#endif
#if 0x073100 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLSSLBACKEND_LIBRESSL", CURLSSLBACKEND_LIBRESSL);
#endif
#if 0x072e00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLSSLBACKEND_MBEDTLS", CURLSSLBACKEND_MBEDTLS);
#endif
#if 0x072200 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLSSLBACKEND_NONE", CURLSSLBACKEND_NONE);
#endif
#if 0x072200 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLSSLBACKEND_NSS", CURLSSLBACKEND_NSS);
#endif
#if 0x072200 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLSSLBACKEND_OPENSSL", CURLSSLBACKEND_OPENSSL);
#endif
#if 0x072200 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLSSLBACKEND_POLARSSL", CURLSSLBACKEND_POLARSSL);
#endif
#if 0x072200 <= LIBCURL_VERSION_NUM && LIBCURL_VERSION_NUM < 0x072601
    luaX_set_field<lua_Integer>(L, -1, "CURLSSLBACKEND_QSOSSL", CURLSSLBACKEND_QSOSSL);
#endif
#if 0x072200 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLSSLBACKEND_SCHANNEL", CURLSSLBACKEND_SCHANNEL);
#endif
#if 0x073100 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLSSLBACKEND_WOLFSSL", CURLSSLBACKEND_WOLFSSL);
#endif
#if 0x071900 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLSSLOPT_ALLOW_BEAST", CURLSSLOPT_ALLOW_BEAST);
#endif
#if 0x072c00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLSSLOPT_NO_REVOKE", CURLSSLOPT_NO_REVOKE);
#endif
#if 0x071100 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLUSESSL_ALL", CURLUSESSL_ALL);
#endif
#if 0x071100 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLUSESSL_CONTROL", CURLUSESSL_CONTROL);
#endif
#if 0x071100 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLUSESSL_NONE", CURLUSESSL_NONE);
#endif
#if 0x071100 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURLUSESSL_TRY", CURLUSESSL_TRY);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURLVERSION_FIRST", CURLVERSION_FIRST);
    luaX_set_field<lua_Integer>(L, -1, "CURLVERSION_FOURTH", CURLVERSION_FOURTH);
    luaX_set_field<lua_Integer>(L, -1, "CURLVERSION_NOW", CURLVERSION_NOW);
    luaX_set_field<lua_Integer>(L, -1, "CURLVERSION_SECOND", CURLVERSION_SECOND);
    luaX_set_field<lua_Integer>(L, -1, "CURLVERSION_THIRD", CURLVERSION_THIRD);
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_CHUNK_BGN_FUNC_FAIL", CURL_CHUNK_BGN_FUNC_FAIL);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_CHUNK_BGN_FUNC_OK", CURL_CHUNK_BGN_FUNC_OK);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_CHUNK_BGN_FUNC_SKIP", CURL_CHUNK_BGN_FUNC_SKIP);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_CHUNK_END_FUNC_FAIL", CURL_CHUNK_END_FUNC_FAIL);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_CHUNK_END_FUNC_OK", CURL_CHUNK_END_FUNC_OK);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURL_CSELECT_ERR", CURL_CSELECT_ERR);
    luaX_set_field<lua_Integer>(L, -1, "CURL_CSELECT_IN", CURL_CSELECT_IN);
    luaX_set_field<lua_Integer>(L, -1, "CURL_CSELECT_OUT", CURL_CSELECT_OUT);
    luaX_set_field<lua_Integer>(L, -1, "CURL_ERROR_SIZE", CURL_ERROR_SIZE);
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_FNMATCHFUNC_FAIL", CURL_FNMATCHFUNC_FAIL);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_FNMATCHFUNC_MATCH", CURL_FNMATCHFUNC_MATCH);
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_FNMATCHFUNC_NOMATCH", CURL_FNMATCHFUNC_NOMATCH);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURL_FORMADD_DISABLED", CURL_FORMADD_DISABLED);
    luaX_set_field<lua_Integer>(L, -1, "CURL_FORMADD_ILLEGAL_ARRAY", CURL_FORMADD_ILLEGAL_ARRAY);
    luaX_set_field<lua_Integer>(L, -1, "CURL_FORMADD_INCOMPLETE", CURL_FORMADD_INCOMPLETE);
    luaX_set_field<lua_Integer>(L, -1, "CURL_FORMADD_MEMORY", CURL_FORMADD_MEMORY);
    luaX_set_field<lua_Integer>(L, -1, "CURL_FORMADD_NULL", CURL_FORMADD_NULL);
    luaX_set_field<lua_Integer>(L, -1, "CURL_FORMADD_OK", CURL_FORMADD_OK);
    luaX_set_field<lua_Integer>(L, -1, "CURL_FORMADD_OPTION_TWICE", CURL_FORMADD_OPTION_TWICE);
    luaX_set_field<lua_Integer>(L, -1, "CURL_FORMADD_UNKNOWN_OPTION", CURL_FORMADD_UNKNOWN_OPTION);
#if 0x071e00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_GLOBAL_ACK_EINTR", CURL_GLOBAL_ACK_EINTR);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURL_GLOBAL_ALL", CURL_GLOBAL_ALL);
    luaX_set_field<lua_Integer>(L, -1, "CURL_GLOBAL_DEFAULT", CURL_GLOBAL_DEFAULT);
    luaX_set_field<lua_Integer>(L, -1, "CURL_GLOBAL_NOTHING", CURL_GLOBAL_NOTHING);
    luaX_set_field<lua_Integer>(L, -1, "CURL_GLOBAL_SSL", CURL_GLOBAL_SSL);
    luaX_set_field<lua_Integer>(L, -1, "CURL_GLOBAL_WIN32", CURL_GLOBAL_WIN32);
#if 0x072e00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_HTTPPOST_BUFFER", CURL_HTTPPOST_BUFFER);
#endif
#if 0x072e00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_HTTPPOST_CALLBACK", CURL_HTTPPOST_CALLBACK);
#endif
#if 0x072e00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_HTTPPOST_FILENAME", CURL_HTTPPOST_FILENAME);
#endif
#if 0x072e00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_HTTPPOST_LARGE", CURL_HTTPPOST_LARGE);
#endif
#if 0x072e00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_HTTPPOST_PTRBUFFER", CURL_HTTPPOST_PTRBUFFER);
#endif
#if 0x072e00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_HTTPPOST_PTRCONTENTS", CURL_HTTPPOST_PTRCONTENTS);
#endif
#if 0x072e00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_HTTPPOST_PTRNAME", CURL_HTTPPOST_PTRNAME);
#endif
#if 0x072e00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_HTTPPOST_READFILE", CURL_HTTPPOST_READFILE);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURL_HTTP_VERSION_1_0", CURL_HTTP_VERSION_1_0);
    luaX_set_field<lua_Integer>(L, -1, "CURL_HTTP_VERSION_1_1", CURL_HTTP_VERSION_1_1);
#if 0x072b00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_HTTP_VERSION_2", CURL_HTTP_VERSION_2);
#endif
#if 0x072100 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_HTTP_VERSION_2_0", CURL_HTTP_VERSION_2_0);
#endif
#if 0x072f00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_HTTP_VERSION_2TLS", CURL_HTTP_VERSION_2TLS);
#endif
#if 0x073100 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_HTTP_VERSION_2_PRIOR_KNOWLEDGE", CURL_HTTP_VERSION_2_PRIOR_KNOWLEDGE);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURL_HTTP_VERSION_NONE", CURL_HTTP_VERSION_NONE);
    luaX_set_field<lua_Integer>(L, -1, "CURL_IPRESOLVE_V4", CURL_IPRESOLVE_V4);
    luaX_set_field<lua_Integer>(L, -1, "CURL_IPRESOLVE_V6", CURL_IPRESOLVE_V6);
    luaX_set_field<lua_Integer>(L, -1, "CURL_IPRESOLVE_WHATEVER", CURL_IPRESOLVE_WHATEVER);
    luaX_set_field<lua_Integer>(L, -1, "CURL_LOCK_ACCESS_NONE", CURL_LOCK_ACCESS_NONE);
    luaX_set_field<lua_Integer>(L, -1, "CURL_LOCK_ACCESS_SHARED", CURL_LOCK_ACCESS_SHARED);
    luaX_set_field<lua_Integer>(L, -1, "CURL_LOCK_ACCESS_SINGLE", CURL_LOCK_ACCESS_SINGLE);
    luaX_set_field<lua_Integer>(L, -1, "CURL_LOCK_DATA_CONNECT", CURL_LOCK_DATA_CONNECT);
    luaX_set_field<lua_Integer>(L, -1, "CURL_LOCK_DATA_COOKIE", CURL_LOCK_DATA_COOKIE);
    luaX_set_field<lua_Integer>(L, -1, "CURL_LOCK_DATA_DNS", CURL_LOCK_DATA_DNS);
    luaX_set_field<lua_Integer>(L, -1, "CURL_LOCK_DATA_NONE", CURL_LOCK_DATA_NONE);
    luaX_set_field<lua_Integer>(L, -1, "CURL_LOCK_DATA_SHARE", CURL_LOCK_DATA_SHARE);
    luaX_set_field<lua_Integer>(L, -1, "CURL_LOCK_DATA_SSL_SESSION", CURL_LOCK_DATA_SSL_SESSION);
#if 0x071307 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_MAX_HTTP_HEADER", CURL_MAX_HTTP_HEADER);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURL_MAX_WRITE_SIZE", CURL_MAX_WRITE_SIZE);
    luaX_set_field<lua_Integer>(L, -1, "CURL_NETRC_IGNORED", CURL_NETRC_IGNORED);
    luaX_set_field<lua_Integer>(L, -1, "CURL_NETRC_OPTIONAL", CURL_NETRC_OPTIONAL);
    luaX_set_field<lua_Integer>(L, -1, "CURL_NETRC_REQUIRED", CURL_NETRC_REQUIRED);
    luaX_set_field<lua_Integer>(L, -1, "CURL_POLL_IN", CURL_POLL_IN);
    luaX_set_field<lua_Integer>(L, -1, "CURL_POLL_INOUT", CURL_POLL_INOUT);
    luaX_set_field<lua_Integer>(L, -1, "CURL_POLL_NONE", CURL_POLL_NONE);
    luaX_set_field<lua_Integer>(L, -1, "CURL_POLL_OUT", CURL_POLL_OUT);
    luaX_set_field<lua_Integer>(L, -1, "CURL_POLL_REMOVE", CURL_POLL_REMOVE);
#if 0x072c00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_PUSH_DENY", CURL_PUSH_DENY);
#endif
#if 0x072c00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_PUSH_OK", CURL_PUSH_OK);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURL_READFUNC_ABORT", CURL_READFUNC_ABORT);
#if 0x071200 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_READFUNC_PAUSE", CURL_READFUNC_PAUSE);
#endif
#if 0x071301 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_REDIR_GET_ALL", CURL_REDIR_GET_ALL);
#endif
#if 0x071301 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_REDIR_POST_301", CURL_REDIR_POST_301);
#endif
#if 0x071301 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_REDIR_POST_302", CURL_REDIR_POST_302);
#endif
#if 0x071901 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_REDIR_POST_303", CURL_REDIR_POST_303);
#endif
#if 0x071301 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_REDIR_POST_ALL", CURL_REDIR_POST_ALL);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_RTSPREQ_ANNOUNCE", CURL_RTSPREQ_ANNOUNCE);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_RTSPREQ_DESCRIBE", CURL_RTSPREQ_DESCRIBE);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_RTSPREQ_GET_PARAMETER", CURL_RTSPREQ_GET_PARAMETER);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_RTSPREQ_NONE", CURL_RTSPREQ_NONE);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_RTSPREQ_OPTIONS", CURL_RTSPREQ_OPTIONS);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_RTSPREQ_PAUSE", CURL_RTSPREQ_PAUSE);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_RTSPREQ_PLAY", CURL_RTSPREQ_PLAY);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_RTSPREQ_RECEIVE", CURL_RTSPREQ_RECEIVE);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_RTSPREQ_RECORD", CURL_RTSPREQ_RECORD);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_RTSPREQ_SETUP", CURL_RTSPREQ_SETUP);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_RTSPREQ_SET_PARAMETER", CURL_RTSPREQ_SET_PARAMETER);
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_RTSPREQ_TEARDOWN", CURL_RTSPREQ_TEARDOWN);
#endif
#if 0x071305 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_SEEKFUNC_CANTSEEK", CURL_SEEKFUNC_CANTSEEK);
#endif
#if 0x071305 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_SEEKFUNC_FAIL", CURL_SEEKFUNC_FAIL);
#endif
#if 0x071305 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_SEEKFUNC_OK", CURL_SEEKFUNC_OK);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURL_SOCKET_BAD", CURL_SOCKET_BAD);
    luaX_set_field<lua_Integer>(L, -1, "CURL_SOCKET_TIMEOUT", CURL_SOCKET_TIMEOUT);
#if 0x071505 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_SOCKOPT_ALREADY_CONNECTED", CURL_SOCKOPT_ALREADY_CONNECTED);
#endif
#if 0x071505 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_SOCKOPT_ERROR", CURL_SOCKOPT_ERROR);
#endif
#if 0x071505 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_SOCKOPT_OK", CURL_SOCKOPT_OK);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURL_SSLVERSION_DEFAULT", CURL_SSLVERSION_DEFAULT);
    luaX_set_field<lua_Integer>(L, -1, "CURL_SSLVERSION_SSLv2", CURL_SSLVERSION_SSLv2);
    luaX_set_field<lua_Integer>(L, -1, "CURL_SSLVERSION_SSLv3", CURL_SSLVERSION_SSLv3);
    luaX_set_field<lua_Integer>(L, -1, "CURL_SSLVERSION_TLSv1", CURL_SSLVERSION_TLSv1);
#if 0x072200 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_SSLVERSION_TLSv1_0", CURL_SSLVERSION_TLSv1_0);
#endif
#if 0x072200 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_SSLVERSION_TLSv1_1", CURL_SSLVERSION_TLSv1_1);
#endif
#if 0x072200 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_SSLVERSION_TLSv1_2", CURL_SSLVERSION_TLSv1_2);
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_SSLVERSION_TLSv1_3", CURL_SSLVERSION_TLSv1_3);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURL_TIMECOND_IFMODSINCE", CURL_TIMECOND_IFMODSINCE);
    luaX_set_field<lua_Integer>(L, -1, "CURL_TIMECOND_IFUNMODSINCE", CURL_TIMECOND_IFUNMODSINCE);
    luaX_set_field<lua_Integer>(L, -1, "CURL_TIMECOND_LASTMOD", CURL_TIMECOND_LASTMOD);
    luaX_set_field<lua_Integer>(L, -1, "CURL_TIMECOND_NONE", CURL_TIMECOND_NONE);
#if 0x071504 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_TLSAUTH_NONE", CURL_TLSAUTH_NONE);
#endif
#if 0x071504 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_TLSAUTH_SRP", CURL_TLSAUTH_SRP);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURL_VERSION_ASYNCHDNS", CURL_VERSION_ASYNCHDNS);
    luaX_set_field<lua_Integer>(L, -1, "CURL_VERSION_CONV", CURL_VERSION_CONV);
#if 0x071306 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_VERSION_CURLDEBUG", CURL_VERSION_CURLDEBUG);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURL_VERSION_DEBUG", CURL_VERSION_DEBUG);
#if 0x072600 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_VERSION_GSSAPI", CURL_VERSION_GSSAPI);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURL_VERSION_GSSNEGOTIATE", CURL_VERSION_GSSNEGOTIATE);
#if 0x072100 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_VERSION_HTTP2", CURL_VERSION_HTTP2);
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_VERSION_HTTPS_PROXY", CURL_VERSION_HTTPS_PROXY);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURL_VERSION_IDN", CURL_VERSION_IDN);
    luaX_set_field<lua_Integer>(L, -1, "CURL_VERSION_IPV6", CURL_VERSION_IPV6);
    luaX_set_field<lua_Integer>(L, -1, "CURL_VERSION_KERBEROS4", CURL_VERSION_KERBEROS4);
#if 0x072800 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_VERSION_KERBEROS5", CURL_VERSION_KERBEROS5);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURL_VERSION_LARGEFILE", CURL_VERSION_LARGEFILE);
    luaX_set_field<lua_Integer>(L, -1, "CURL_VERSION_LIBZ", CURL_VERSION_LIBZ);
    luaX_set_field<lua_Integer>(L, -1, "CURL_VERSION_NTLM", CURL_VERSION_NTLM);
#if 0x071600 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_VERSION_NTLM_WB", CURL_VERSION_NTLM_WB);
#endif
#if 0x072f00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_VERSION_PSL", CURL_VERSION_PSL);
#endif
    luaX_set_field<lua_Integer>(L, -1, "CURL_VERSION_SPNEGO", CURL_VERSION_SPNEGO);
    luaX_set_field<lua_Integer>(L, -1, "CURL_VERSION_SSL", CURL_VERSION_SSL);
    luaX_set_field<lua_Integer>(L, -1, "CURL_VERSION_SSPI", CURL_VERSION_SSPI);
#if 0x071504 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_VERSION_TLSAUTH_SRP", CURL_VERSION_TLSAUTH_SRP);
#endif
#if 0x072800 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_VERSION_UNIX_SOCKETS", CURL_VERSION_UNIX_SOCKETS);
#endif
#if 0x071c00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_WAIT_POLLIN", CURL_WAIT_POLLIN);
#endif
#if 0x071c00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_WAIT_POLLOUT", CURL_WAIT_POLLOUT);
#endif
#if 0x071c00 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_WAIT_POLLPRI", CURL_WAIT_POLLPRI);
#endif
#if 0x071200 <= LIBCURL_VERSION_NUM
    luaX_set_field<lua_Integer>(L, -1, "CURL_WRITEFUNC_PAUSE", CURL_WRITEFUNC_PAUSE);
#endif
  }

  easy_setopt_param_enum easy_setopt_param(CURLoption option) {
#if 0x071800 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_ACCEPTTIMEOUT_MS) { return easy_setopt_param_long; }
#endif
#if 0x071506 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_ACCEPT_ENCODING) { return easy_setopt_param_char_p; }
#endif
#if 0x071300 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_ADDRESS_SCOPE) { return easy_setopt_param_long; }
#endif
#if 0x071100 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_APPEND) { return easy_setopt_param_long; }
#endif
    if (option == CURLOPT_AUTOREFERER) { return easy_setopt_param_long; }
    if (option == CURLOPT_BUFFERSIZE) { return easy_setopt_param_long; }
    if (option == CURLOPT_CAINFO) { return easy_setopt_param_char_p; }
    if (option == CURLOPT_CAPATH) { return easy_setopt_param_char_p; }
#if 0x071301 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_CERTINFO) { return easy_setopt_param_long; }
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_CHUNK_BGN_FUNCTION) { return easy_setopt_param_callback; }
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_CHUNK_DATA) { return easy_setopt_param_void_p; }
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_CHUNK_END_FUNCTION) { return easy_setopt_param_callback; }
#endif
#if 0x071507 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_CLOSESOCKETDATA) { return easy_setopt_param_void_p; }
#endif
#if 0x071507 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_CLOSESOCKETFUNCTION) { return easy_setopt_param_callback; }
#endif
    if (option == CURLOPT_CONNECTTIMEOUT) { return easy_setopt_param_long; }
    if (option == CURLOPT_CONNECTTIMEOUT_MS) { return easy_setopt_param_long; }
    if (option == CURLOPT_CONNECT_ONLY) { return easy_setopt_param_long; }
#if 0x073100 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_CONNECT_TO) { return easy_setopt_param_struct_curl_slist_p; }
#endif
    if (option == CURLOPT_CONV_FROM_NETWORK_FUNCTION) { return easy_setopt_param_callback; }
    if (option == CURLOPT_CONV_FROM_UTF8_FUNCTION) { return easy_setopt_param_callback; }
    if (option == CURLOPT_CONV_TO_NETWORK_FUNCTION) { return easy_setopt_param_callback; }
    if (option == CURLOPT_COOKIE) { return easy_setopt_param_char_p; }
    if (option == CURLOPT_COOKIEFILE) { return easy_setopt_param_char_p; }
    if (option == CURLOPT_COOKIEJAR) { return easy_setopt_param_char_p; }
    if (option == CURLOPT_COOKIELIST) { return easy_setopt_param_char_p; }
    if (option == CURLOPT_COOKIESESSION) { return easy_setopt_param_long; }
#if 0x071101 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_COPYPOSTFIELDS) { return easy_setopt_param_char_p; }
#endif
    if (option == CURLOPT_CRLF) { return easy_setopt_param_long; }
#if 0x071300 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_CRLFILE) { return easy_setopt_param_char_p; }
#endif
    if (option == CURLOPT_CUSTOMREQUEST) { return easy_setopt_param_char_p; }
    if (option == CURLOPT_DEBUGDATA) { return easy_setopt_param_void_p; }
    if (option == CURLOPT_DEBUGFUNCTION) { return easy_setopt_param_callback; }
#if 0x072d00 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_DEFAULT_PROTOCOL) { return easy_setopt_param_char_p; }
#endif
#if 0x071100 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_DIRLISTONLY) { return easy_setopt_param_long; }
#endif
    if (option == CURLOPT_DNS_CACHE_TIMEOUT) { return easy_setopt_param_long; }
#if 0x072100 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_DNS_INTERFACE) { return easy_setopt_param_char_p; }
#endif
#if 0x072100 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_DNS_LOCAL_IP4) { return easy_setopt_param_char_p; }
#endif
#if 0x072100 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_DNS_LOCAL_IP6) { return easy_setopt_param_char_p; }
#endif
#if 0x071800 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_DNS_SERVERS) { return easy_setopt_param_char_p; }
#endif
    if (option == CURLOPT_EGDSOCKET) { return easy_setopt_param_char_p; }
    if (option == CURLOPT_ENCODING) { return easy_setopt_param_char_p; }
    if (option == CURLOPT_ERRORBUFFER) { return easy_setopt_param_char_p; }
#if 0x072400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_EXPECT_100_TIMEOUT_MS) { return easy_setopt_param_long; }
#endif
    if (option == CURLOPT_FAILONERROR) { return easy_setopt_param_long; }
    if (option == CURLOPT_FILETIME) { return easy_setopt_param_long; }
#if 0x071500 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_FNMATCH_DATA) { return easy_setopt_param_void_p; }
#endif
#if 0x071500 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_FNMATCH_FUNCTION) { return easy_setopt_param_callback; }
#endif
    if (option == CURLOPT_FOLLOWLOCATION) { return easy_setopt_param_long; }
    if (option == CURLOPT_FORBID_REUSE) { return easy_setopt_param_long; }
    if (option == CURLOPT_FRESH_CONNECT) { return easy_setopt_param_long; }
    if (option == CURLOPT_FTPPORT) { return easy_setopt_param_char_p; }
    if (option == CURLOPT_FTPSSLAUTH) { return easy_setopt_param_long; }
    if (option == CURLOPT_FTP_ACCOUNT) { return easy_setopt_param_char_p; }
    if (option == CURLOPT_FTP_ALTERNATIVE_TO_USER) { return easy_setopt_param_char_p; }
    if (option == CURLOPT_FTP_CREATE_MISSING_DIRS) { return easy_setopt_param_long; }
    if (option == CURLOPT_FTP_FILEMETHOD) { return easy_setopt_param_long; }
    if (option == CURLOPT_FTP_RESPONSE_TIMEOUT) { return easy_setopt_param_long; }
    if (option == CURLOPT_FTP_SKIP_PASV_IP) { return easy_setopt_param_long; }
    if (option == CURLOPT_FTP_SSL_CCC) { return easy_setopt_param_long; }
    if (option == CURLOPT_FTP_USE_EPRT) { return easy_setopt_param_long; }
    if (option == CURLOPT_FTP_USE_EPSV) { return easy_setopt_param_long; }
#if 0x071400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_FTP_USE_PRET) { return easy_setopt_param_long; }
#endif
#if 0x071600 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_GSSAPI_DELEGATION) { return easy_setopt_param_long; }
#endif
    if (option == CURLOPT_HEADER) { return easy_setopt_param_long; }
    if (option == CURLOPT_HEADERDATA) { return easy_setopt_param_void_p; }
    if (option == CURLOPT_HEADERFUNCTION) { return easy_setopt_param_callback; }
#if 0x072500 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_HEADEROPT) { return easy_setopt_param_long; }
#endif
    if (option == CURLOPT_HTTP200ALIASES) { return easy_setopt_param_struct_curl_slist_p; }
    if (option == CURLOPT_HTTPAUTH) { return easy_setopt_param_long; }
    if (option == CURLOPT_HTTPGET) { return easy_setopt_param_long; }
    if (option == CURLOPT_HTTPHEADER) { return easy_setopt_param_struct_curl_slist_p; }
    if (option == CURLOPT_HTTPPOST) { return easy_setopt_param_struct_curl_httppost_p; }
    if (option == CURLOPT_HTTPPROXYTUNNEL) { return easy_setopt_param_long; }
    if (option == CURLOPT_HTTP_CONTENT_DECODING) { return easy_setopt_param_long; }
    if (option == CURLOPT_HTTP_TRANSFER_DECODING) { return easy_setopt_param_long; }
    if (option == CURLOPT_HTTP_VERSION) { return easy_setopt_param_long; }
    if (option == CURLOPT_IGNORE_CONTENT_LENGTH) { return easy_setopt_param_long; }
    if (option == CURLOPT_INFILESIZE) { return easy_setopt_param_long; }
    if (option == CURLOPT_INFILESIZE_LARGE) { return easy_setopt_param_curl_off_t; }
    if (option == CURLOPT_INTERFACE) { return easy_setopt_param_char_p; }
#if 0x071400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_INTERLEAVEDATA) { return easy_setopt_param_void_p; }
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_INTERLEAVEFUNCTION) { return easy_setopt_param_callback; }
#endif
    if (option == CURLOPT_IOCTLDATA) { return easy_setopt_param_void_p; }
    if (option == CURLOPT_IOCTLFUNCTION) { return easy_setopt_param_callback; }
    if (option == CURLOPT_IPRESOLVE) { return easy_setopt_param_long; }
#if 0x071300 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_ISSUERCERT) { return easy_setopt_param_char_p; }
#endif
#if 0x071100 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_KEYPASSWD) { return easy_setopt_param_char_p; }
#endif
#if 0x073300 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_KEEP_SENDING_ON_ERROR) { return easy_setopt_param_long; }
#endif
    if (option == CURLOPT_KRBLEVEL) { return easy_setopt_param_char_p; }
    if (option == CURLOPT_LOCALPORT) { return easy_setopt_param_long; }
    if (option == CURLOPT_LOCALPORTRANGE) { return easy_setopt_param_long; }
#if 0x072200 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_LOGIN_OPTIONS) { return easy_setopt_param_char_p; }
#endif
    if (option == CURLOPT_LOW_SPEED_LIMIT) { return easy_setopt_param_long; }
    if (option == CURLOPT_LOW_SPEED_TIME) { return easy_setopt_param_long; }
#if 0x071900 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_MAIL_AUTH) { return easy_setopt_param_char_p; }
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_MAIL_FROM) { return easy_setopt_param_char_p; }
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_MAIL_RCPT) { return easy_setopt_param_struct_curl_slist_p; }
#endif
    if (option == CURLOPT_MAXCONNECTS) { return easy_setopt_param_long; }
    if (option == CURLOPT_MAXFILESIZE) { return easy_setopt_param_long; }
    if (option == CURLOPT_MAXFILESIZE_LARGE) { return easy_setopt_param_curl_off_t; }
    if (option == CURLOPT_MAXREDIRS) { return easy_setopt_param_long; }
    if (option == CURLOPT_MAX_RECV_SPEED_LARGE) { return easy_setopt_param_curl_off_t; }
    if (option == CURLOPT_MAX_SEND_SPEED_LARGE) { return easy_setopt_param_curl_off_t; }
    if (option == CURLOPT_NETRC) { return easy_setopt_param_long; }
    if (option == CURLOPT_NETRC_FILE) { return easy_setopt_param_char_p; }
    if (option == CURLOPT_NEW_DIRECTORY_PERMS) { return easy_setopt_param_long; }
    if (option == CURLOPT_NEW_FILE_PERMS) { return easy_setopt_param_long; }
    if (option == CURLOPT_NOBODY) { return easy_setopt_param_long; }
    if (option == CURLOPT_NOPROGRESS) { return easy_setopt_param_long; }
#if 0x071304 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_NOPROXY) { return easy_setopt_param_char_p; }
#endif
    if (option == CURLOPT_NOSIGNAL) { return easy_setopt_param_long; }
#if 0x071101 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_OPENSOCKETDATA) { return easy_setopt_param_void_p; }
#endif
#if 0x071101 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_OPENSOCKETFUNCTION) { return easy_setopt_param_callback; }
#endif
#if 0x071301 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_PASSWORD) { return easy_setopt_param_char_p; }
#endif
#if 0x072a00 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_PATH_AS_IS) { return easy_setopt_param_long; }
#endif
#if 0x072700 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_PINNEDPUBLICKEY) { return easy_setopt_param_char_p; }
#endif
#if 0x072b00 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_PIPEWAIT) { return easy_setopt_param_long; }
#endif
    if (option == CURLOPT_PORT) { return easy_setopt_param_long; }
    if (option == CURLOPT_POST) { return easy_setopt_param_long; }
#if 0x071101 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_POST301) { return easy_setopt_param_long; }
#endif
    if (option == CURLOPT_POSTFIELDS) { return easy_setopt_param_char_p; }
    if (option == CURLOPT_POSTFIELDSIZE) { return easy_setopt_param_long; }
    if (option == CURLOPT_POSTFIELDSIZE_LARGE) { return easy_setopt_param_curl_off_t; }
    if (option == CURLOPT_POSTQUOTE) { return easy_setopt_param_struct_curl_slist_p; }
#if 0x071301 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_POSTREDIR) { return easy_setopt_param_long; }
#endif
    if (option == CURLOPT_PREQUOTE) { return easy_setopt_param_char_p; }
#if 0x073400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_PRE_PROXY) { return easy_setopt_param_char_p; }
#endif
    if (option == CURLOPT_PRIVATE) { return easy_setopt_param_void_p; }
    if (option == CURLOPT_PROGRESSDATA) { return easy_setopt_param_void_p; }
    if (option == CURLOPT_PROGRESSFUNCTION) { return easy_setopt_param_callback; }
#if 0x071304 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_PROTOCOLS) { return easy_setopt_param_long; }
#endif
    if (option == CURLOPT_PROXY) { return easy_setopt_param_char_p; }
    if (option == CURLOPT_PROXYAUTH) { return easy_setopt_param_long; }
#if 0x072500 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_PROXYHEADER) { return easy_setopt_param_struct_curl_slist_p; }
#endif
#if 0x071301 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_PROXYPASSWORD) { return easy_setopt_param_char_p; }
#endif
    if (option == CURLOPT_PROXYPORT) { return easy_setopt_param_long; }
    if (option == CURLOPT_PROXYTYPE) { return easy_setopt_param_long; }
#if 0x071301 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_PROXYUSERNAME) { return easy_setopt_param_char_p; }
#endif
    if (option == CURLOPT_PROXYUSERPWD) { return easy_setopt_param_char_p; }
#if 0x073400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_PROXY_CAINFO) { return easy_setopt_param_char_p; }
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_PROXY_CAPATH) { return easy_setopt_param_char_p; }
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_PROXY_CRLFILE) { return easy_setopt_param_char_p; }
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_PROXY_KEYPASSWD) { return easy_setopt_param_char_p; }
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_PROXY_PINNEDPUBLICKEY) { return easy_setopt_param_char_p; }
#endif
#if 0x072b00 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_PROXY_SERVICE_NAME) { return easy_setopt_param_char_p; }
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_PROXY_SSLCERT) { return easy_setopt_param_char_p; }
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_PROXY_SSLCERTTYPE) { return easy_setopt_param_char_p; }
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_PROXY_SSLKEY) { return easy_setopt_param_char_p; }
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_PROXY_SSLKEYTYPE) { return easy_setopt_param_char_p; }
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_PROXY_SSLVERSION) { return easy_setopt_param_long; }
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_PROXY_SSL_CIPHER_LIST) { return easy_setopt_param_char_p; }
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_PROXY_SSL_OPTIONS) { return easy_setopt_param_long; }
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_PROXY_SSL_VERIFYHOST) { return easy_setopt_param_long; }
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_PROXY_SSL_VERIFYPEER) { return easy_setopt_param_long; }
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_PROXY_TLSAUTH_PASSWORD) { return easy_setopt_param_char_p; }
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_PROXY_TLSAUTH_TYPE) { return easy_setopt_param_char_p; }
#endif
#if 0x073400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_PROXY_TLSAUTH_USERNAME) { return easy_setopt_param_char_p; }
#endif
#if 0x071200 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_PROXY_TRANSFER_MODE) { return easy_setopt_param_long; }
#endif
    if (option == CURLOPT_PUT) { return easy_setopt_param_long; }
    if (option == CURLOPT_QUOTE) { return easy_setopt_param_struct_curl_slist_p; }
    if (option == CURLOPT_RANDOM_FILE) { return easy_setopt_param_char_p; }
    if (option == CURLOPT_RANGE) { return easy_setopt_param_char_p; }
    if (option == CURLOPT_READDATA) { return easy_setopt_param_void_p; }
    if (option == CURLOPT_READFUNCTION) { return easy_setopt_param_callback; }
#if 0x071304 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_REDIR_PROTOCOLS) { return easy_setopt_param_long; }
#endif
    if (option == CURLOPT_REFERER) { return easy_setopt_param_char_p; }
#if 0x071503 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_RESOLVE) { return easy_setopt_param_struct_curl_slist_p; }
#endif
    if (option == CURLOPT_RESUME_FROM) { return easy_setopt_param_long; }
    if (option == CURLOPT_RESUME_FROM_LARGE) { return easy_setopt_param_curl_off_t; }
#if 0x071400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_RTSPHEADER) { return easy_setopt_param_struct_curl_slist_p; }
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_RTSP_CLIENT_CSEQ) { return easy_setopt_param_long; }
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_RTSP_REQUEST) { return easy_setopt_param_long; }
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_RTSP_SERVER_CSEQ) { return easy_setopt_param_long; }
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_RTSP_SESSION_ID) { return easy_setopt_param_char_p; }
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_RTSP_STREAM_URI) { return easy_setopt_param_char_p; }
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_RTSP_TRANSPORT) { return easy_setopt_param_char_p; }
#endif
#if 0x071f00 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_SASL_IR) { return easy_setopt_param_long; }
#endif
#if 0x071200 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_SEEKDATA) { return easy_setopt_param_void_p; }
#endif
#if 0x071200 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_SEEKFUNCTION) { return easy_setopt_param_callback; }
#endif
#if 0x071400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_SERVER_RESPONSE_TIMEOUT) { return easy_setopt_param_long; }
#endif
#if 0x072b00 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_SERVICE_NAME) { return easy_setopt_param_char_p; }
#endif
    if (option == CURLOPT_SHARE) { return easy_setopt_param_CURLSH_p; }
    if (option == CURLOPT_SOCKOPTDATA) { return easy_setopt_param_void_p; }
    if (option == CURLOPT_SOCKOPTFUNCTION) { return easy_setopt_param_callback; }
#if 0x071304 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_SOCKS5_GSSAPI_NEC) { return easy_setopt_param_long; }
#endif
#if 0x071304 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_SOCKS5_GSSAPI_SERVICE) { return easy_setopt_param_char_p; }
#endif
    if (option == CURLOPT_SSH_AUTH_TYPES) { return easy_setopt_param_long; }
#if 0x071101 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_SSH_HOST_PUBLIC_KEY_MD5) { return easy_setopt_param_char_p; }
#endif
#if 0x071306 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_SSH_KEYDATA) { return easy_setopt_param_void_p; }
#endif
#if 0x071306 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_SSH_KEYFUNCTION) { return easy_setopt_param_callback; }
#endif
#if 0x071306 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_SSH_KNOWNHOSTS) { return easy_setopt_param_char_p; }
#endif
    if (option == CURLOPT_SSH_PRIVATE_KEYFILE) { return easy_setopt_param_char_p; }
    if (option == CURLOPT_SSH_PUBLIC_KEYFILE) { return easy_setopt_param_char_p; }
    if (option == CURLOPT_SSLCERT) { return easy_setopt_param_char_p; }
    if (option == CURLOPT_SSLCERTTYPE) { return easy_setopt_param_char_p; }
    if (option == CURLOPT_SSLENGINE) { return easy_setopt_param_char_p; }
    if (option == CURLOPT_SSLENGINE_DEFAULT) { return easy_setopt_param_long; }
    if (option == CURLOPT_SSLKEY) { return easy_setopt_param_char_p; }
    if (option == CURLOPT_SSLKEYTYPE) { return easy_setopt_param_char_p; }
    if (option == CURLOPT_SSLVERSION) { return easy_setopt_param_long; }
    if (option == CURLOPT_SSL_CIPHER_LIST) { return easy_setopt_param_char_p; }
    if (option == CURLOPT_SSL_CTX_DATA) { return easy_setopt_param_void_p; }
    if (option == CURLOPT_SSL_CTX_FUNCTION) { return easy_setopt_param_callback; }
#if 0x072400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_SSL_ENABLE_ALPN) { return easy_setopt_param_long; }
#endif
#if 0x072400 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_SSL_ENABLE_NPN) { return easy_setopt_param_long; }
#endif
#if 0x072a00 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_SSL_FALSESTART) { return easy_setopt_param_long; }
#endif
#if 0x071900 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_SSL_OPTIONS) { return easy_setopt_param_long; }
#endif
    if (option == CURLOPT_SSL_SESSIONID_CACHE) { return easy_setopt_param_long; }
    if (option == CURLOPT_SSL_VERIFYHOST) { return easy_setopt_param_long; }
    if (option == CURLOPT_SSL_VERIFYPEER) { return easy_setopt_param_long; }
#if 0x072900 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_SSL_VERIFYSTATUS) { return easy_setopt_param_long; }
#endif
    if (option == CURLOPT_STDERR) { return easy_setopt_param_FILE_p; }
#if 0x072e00 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_STREAM_DEPENDS) { return easy_setopt_param_CURL_p; }
#endif
#if 0x072e00 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_STREAM_DEPENDS_E) { return easy_setopt_param_CURL_p; }
#endif
#if 0x072e00 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_STREAM_WEIGHT) { return easy_setopt_param_long; }
#endif
#if 0x071900 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_TCP_KEEPALIVE) { return easy_setopt_param_long; }
#endif
#if 0x071900 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_TCP_KEEPIDLE) { return easy_setopt_param_long; }
#endif
#if 0x071900 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_TCP_KEEPINTVL) { return easy_setopt_param_long; }
#endif
    if (option == CURLOPT_TCP_NODELAY) { return easy_setopt_param_long; }
#if 0x073100 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_TCP_FASTOPEN) { return easy_setopt_param_long; }
#endif
    if (option == CURLOPT_TELNETOPTIONS) { return easy_setopt_param_struct_curl_slist_p; }
#if 0x071304 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_TFTP_BLKSIZE) { return easy_setopt_param_long; }
#endif
#if 0x073000 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_TFTP_NO_OPTIONS) { return easy_setopt_param_long; }
#endif
    if (option == CURLOPT_TIMECONDITION) { return easy_setopt_param_long; }
    if (option == CURLOPT_TIMEOUT) { return easy_setopt_param_long; }
    if (option == CURLOPT_TIMEOUT_MS) { return easy_setopt_param_long; }
    if (option == CURLOPT_TIMEVALUE) { return easy_setopt_param_long; }
#if 0x071504 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_TLSAUTH_PASSWORD) { return easy_setopt_param_char_p; }
#endif
#if 0x071504 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_TLSAUTH_TYPE) { return easy_setopt_param_char_p; }
#endif
#if 0x071504 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_TLSAUTH_USERNAME) { return easy_setopt_param_char_p; }
#endif
    if (option == CURLOPT_TRANSFERTEXT) { return easy_setopt_param_long; }
#if 0x071506 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_TRANSFER_ENCODING) { return easy_setopt_param_long; }
#endif
#if 0x072800 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_UNIX_SOCKET_PATH) { return easy_setopt_param_char_p; }
#endif
    if (option == CURLOPT_UNRESTRICTED_AUTH) { return easy_setopt_param_long; }
    if (option == CURLOPT_UPLOAD) { return easy_setopt_param_long; }
    if (option == CURLOPT_URL) { return easy_setopt_param_char_p; }
    if (option == CURLOPT_USERAGENT) { return easy_setopt_param_char_p; }
#if 0x071301 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_USERNAME) { return easy_setopt_param_char_p; }
#endif
    if (option == CURLOPT_USERPWD) { return easy_setopt_param_char_p; }
#if 0x071100 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_USE_SSL) { return easy_setopt_param_long; }
#endif
    if (option == CURLOPT_VERBOSE) { return easy_setopt_param_long; }
#if 0x071500 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_WILDCARDMATCH) { return easy_setopt_param_long; }
#endif
    if (option == CURLOPT_WRITEDATA) { return easy_setopt_param_void_p; }
    if (option == CURLOPT_WRITEFUNCTION) { return easy_setopt_param_callback; }
    if (option == CURLOPT_WRITEHEADER) { return easy_setopt_param_void_p; }
#if 0x072000 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_XFERINFODATA) { return easy_setopt_param_void_p; }
#endif
#if 0x072000 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_XFERINFOFUNCTION) { return easy_setopt_param_callback; }
#endif
#if 0x072100 <= LIBCURL_VERSION_NUM
    if (option == CURLOPT_XOAUTH2_BEARER) { return easy_setopt_param_char_p; }
#endif
    return easy_setopt_param_unknown;
  }

  multi_setopt_param_enum multi_setopt_param(CURLMoption option) {
#if 0x071e00 <= LIBCURL_VERSION_NUM
    if (option == CURLMOPT_CHUNK_LENGTH_PENALTY_SIZE) { return multi_setopt_param_long; }
#endif
#if 0x071e00 <= LIBCURL_VERSION_NUM
    if (option == CURLMOPT_CONTENT_LENGTH_PENALTY_SIZE) { return multi_setopt_param_long; }
#endif
    if (option == CURLMOPT_MAXCONNECTS) { return multi_setopt_param_long; }
#if 0x071e00 <= LIBCURL_VERSION_NUM
    if (option == CURLMOPT_MAX_HOST_CONNECTIONS) { return multi_setopt_param_long; }
#endif
#if 0x071e00 <= LIBCURL_VERSION_NUM
    if (option == CURLMOPT_MAX_PIPELINE_LENGTH) { return multi_setopt_param_long; }
#endif
#if 0x071e00 <= LIBCURL_VERSION_NUM
    if (option == CURLMOPT_MAX_TOTAL_CONNECTIONS) { return multi_setopt_param_long; }
#endif
    if (option == CURLMOPT_PIPELINING) { return multi_setopt_param_long; }
#if 0x071e00 <= LIBCURL_VERSION_NUM
    if (option == CURLMOPT_PIPELINING_SERVER_BL) { return multi_setopt_param_char_pp; }
#endif
#if 0x071e00 <= LIBCURL_VERSION_NUM
    if (option == CURLMOPT_PIPELINING_SITE_BL) { return multi_setopt_param_char_pp; }
#endif
#if 0x072c00 <= LIBCURL_VERSION_NUM
    if (option == CURLMOPT_PUSHDATA) { return multi_setopt_param_void_p; }
#endif
#if 0x072c00 <= LIBCURL_VERSION_NUM
    if (option == CURLMOPT_PUSHFUNCTION) { return multi_setopt_param_callback; }
#endif
    if (option == CURLMOPT_SOCKETDATA) { return multi_setopt_param_void_p; }
    if (option == CURLMOPT_SOCKETFUNCTION) { return multi_setopt_param_callback; }
    if (option == CURLMOPT_TIMERDATA) { return multi_setopt_param_void_p; }
    if (option == CURLMOPT_TIMERFUNCTION) { return multi_setopt_param_callback; }
    return multi_setopt_param_unknown;
  }

  const char* error_to_string(CURLFORMcode code) {
    switch (code) {
      case CURL_FORMADD_DISABLED: return "CURL_FORMADD_DISABLED";
      case CURL_FORMADD_ILLEGAL_ARRAY: return "CURL_FORMADD_ILLEGAL_ARRAY";
      case CURL_FORMADD_INCOMPLETE: return "CURL_FORMADD_INCOMPLETE";
      case CURL_FORMADD_MEMORY: return "CURL_FORMADD_MEMORY";
      case CURL_FORMADD_NULL: return "CURL_FORMADD_NULL";
      case CURL_FORMADD_OK: return "CURL_FORMADD_OK";
      case CURL_FORMADD_OPTION_TWICE: return "CURL_FORMADD_OPTION_TWICE";
      case CURL_FORMADD_UNKNOWN_OPTION: return "CURL_FORMADD_UNKNOWN_OPTION";
      default: return "CURLFORMcode unknown";
    }
  }
}
