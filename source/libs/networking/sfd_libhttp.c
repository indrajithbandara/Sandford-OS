/* sfd_libhttp.c - This file is part of Project Sandford, a New Operating System.
 * Copyright 2016, 2017 Brian Millar <brianmillar@protonmail.ch>
 *
 * Project Sandford is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Project Sandford is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Project Sandford.  If not, see <http://www.gnu.org/licenses/>.
 */

char *http_methods = {"GET", "HEAD", "POST", "PUT", "DELETE",
                      "CONNECT", "OPTIONS", "TRACE", "PATCH"};

typedef struct HTTP_REQUEST_HEADER {
    Accept
    Accept-Charset
    Accept-Encoding
    Accept-Language
    Accept-Datetime
    Authorization
    Cache-Controls
    Connection
    Cookie
    Content-Length
    Content-MD5
    Content-Type
    Date
    Except
    Forwarded
    From
    Host
    If-Match
    If-Modified-Since
    If-None-Match
    If-Range
    If-Unmodified-Since
    Max-Forwards
    Origin
    Pragma
    Proxy-Authorization
    Range
    Referer
    TE
    User-Agent
    Upgrade
    Via
    Warning

    /* Non-Standard */
    X-Requested-Without
    DNT
    X-Forwarded-For
    X-Forwarded-Host
    X-Forwarded-Proto
    Front-End-Https
    X-Http-Method-Override
    X-ATT-DeviceId
    X-Wap-Profile
    Proxy-Connection
    X-UIDH
    X-Csrf-Token
    X-Request-ID
    X-Correlation-ID
} HTTP_REQUEST_HEADER;

typedef struct HTTP_RESPONSE_HEADER {
    Access-Control-Allow-Origin
    Accept-Patch
    Accept-Ranges
    Age
    Allow
    Alt-Svc
    Cache-Control
    Connection
    Content-Disposition
    Content-Encoding
    Content-Language
    Content-Length
    Content-Location
    Content-MD5
    Content-Range
    Content-Type
    Date
    ETag
    Expires
    Last-Modified
    Link
    Location
    P3P
    Pragma
    Proxy-Authorization
    Public-Key-Pins
    Refresh
    Retry-After
    Server
    Set-Cookie
    Status
    Strict-Transport-Security
    Trailer
    Transfer-Encoding
    TSV
    Upgrade
    Vary
    Via
    Warning
    WWW-Authenticate
    X-Frame-Options

    /* Non-Standard */
    X-XSS-Protection
    Content-Security-Policy
    X-Content-Type-Options
    X-Powered-By
    X-UA-Compatible
    X-Content-Duration
    Upgrade-Inscure-Requests
    X-Request-ID
    X-Correlation-ID
} HTTP_RESPONSE_HEADER;

char *sfd_net_http_status_lookup(int code) {
    switch (code) {

        /* Informational */
        case 100: return "Continue";
        case 101: return "Switching Protocols";
        case 102: return "Processing";

        /* Success */
        case 200: return "OK";
        case 201: return "Created";
        case 202: return "Accepted";
        case 203: return "Non-Authoritative Information";
        case 204: return "No Content";
        case 205: return "Reset Content";
        case 206: return "Partial Content";
        case 207: return "Multi-Status";
        case 208: return "Already Reported";
        case 226: return "IM Used";

        /* Redirection */
        case 300: return "Multiple Choices";
        case 301: return "Moved Permanently";
        case 302: return "Found";
        case 303: return "See Other";
        case 304: return "Not Modified";
        case 305: return "Use Proxy";
        case 306: return "Switch Proxy";
        case 307: return "Temporary Redirect";
        case 308: return "Permanent Redirect";

        /* Client Error */
        case 400: return "Bad Request";
        case 401: return "Unauthorized";
        case 402: return "Payment Required";
        case 403: return "Forbidden";
        case 404: return "Not Found";
        case 405: return "Method Not Allowed";
        case 406: return "Not Acceptable";
        case 407: return "Proxy Authentication Required";
        case 408: return "Request Timeout";
        case 409: return "Conflict";
        case 410: return "Gone";
        case 411: return "Length Required";
        case 412: return "Precondition Failed";
        case 413: return "Payload Too Large";
        case 414: return "URI Too Long";
        case 415: return "Unsupported Media Type";
        case 416: return "Range Not Satisfiable";
        case 417: return "Expectation Failed";
        case 418: return "I'm a Teapot";
        case 421: return "Misdirected Request";
        case 422: return "Unprocessable Entity";
        case 423: return "Locked";
        case 424: return "Failed Depenency";
        case 426: return "Upgrade Required";
        case 428: return "Precondition Required";
        case 429: return "Too Many Requests";
        case 431: return "Request Header Fields Too Large";
        case 451: return "Unavailable For Legal Reasons"; /* Can Also Be Unofficial "Redirect" (IIS) */

        /* Server Error */
        case 500: return "Internal Server Error";
        case 501: return "Not Implemented";
        case 502: return "Bad Gateway";
        case 503: return "Service Unavailable";
        case 504: return "Gateway Time-out";
        case 505: return "HTTP Version Not Supported";
        case 506: return "Variant Also Negotiates";
        case 507: return "Insufficient Storage";
        case 508: return "Loop Detected";
        case 510: return "Not Extended";
        case 511: return "Network Authentication Required";

        /* Unofficial */
        case 103: return "Checkpoint";                           /* Can Also Be "Early Hints" */
        case 420: return "Method Failure";                       /* Spring Framework */
        case 440: return "Login Time-out";                       /* IIS */
        case 444: return "Connection Closed Without Response";   /* nginx */
        case 449: return "Retry With";                           /* IIS */
        case 450: return "Blocked by Windows Parental Controls"; /* Microsoft */
        case 495: return "SSL Certificate Error";                /* nginx */
        case 496: return "SSL Certificate Required";             /* nginx */
        case 497: return "HTTP Request Sent to HTTPS Port";      /* nginx */
        case 498: return "Invalid Token";                        /* Esri */
        case 499: return "Client Closed Request";                /* nginx, Can Also Be "Token Required" (Esri) */
        case 509: return "Bandwidth Limit Exceeded";             /* Apache/cPanel */
        case 520: return "Unknown Error";                        /* Cloudflare */
        case 521: return "Web Server is Down";                   /* Cloudflare */
        case 522: return "Connection Timed Out";                 /* Cloudflare */
        case 523: return "Origin is Unreachable";                /* Cloudflare */
        case 524: return "A Timeout Occurred";                   /* Cloudflare */
        case 525: return "SSL Handshake Failed";                 /* Cloudflare */
        case 526: return "Invalid SSL Certificate";              /* Cloudflare */
        case 527: return "Railgun Error";                        /* Cloudflare */
        case 530: return "Site is Frozen";                       /* Pantheon */
        case 598: return "Network Read Timeout Error";
        case 599: return "Network Connect Timeout Error";

        default:  return "Invalid HTTP Status Code";
    }
}
