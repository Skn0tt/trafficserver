.. Licensed to the Apache Software Foundation (ASF) under one
   or more contributor license agreements.  See the NOTICE file
   distributed with this work for additional information
   regarding copyright ownership.  The ASF licenses this file
   to you under the Apache License, Version 2.0 (the
   "License"); you may not use this file except in compliance
   with the License.  You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing,
   software distributed under the License is distributed on an
   "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
   KIND, either express or implied.  See the License for the
   specific language governing permissions and limitations
   under the License.

.. include:: ../../common.defs

.. _admin-plugins:

Plugins
*******

.. toctree::
   :maxdepth: 2

Overview
========

One of the key features of |ATS| is its modularity. Features that aren't needed
in the core simply aren't there. This helps to provide an additional guarantee
that our core can remain fast by concentrating on the things that we always
provide: caching and proxying.

All other functionality can be moved into plugins and by offering a consistent
C API, everyone can implement their own functionality, without having to touch
the core.

Stable plugins
==============

Plugins that are considered stable are installed by default in |TS| releases.

.. toctree::
   :hidden:

   AWS S3 Authentication <s3_auth.en>
   AuthProxy <authproxy.en>
   Background Fetch <background_fetch.en>
   Cache Key Manipulation <cachekey.en>
   Cache Promotion Policies <cache_promote.en>
   Cache Range Requests <cache_range_requests.en>
   Combo Handler <combo_handler.en>
   Configuration Remap <conf_remap.en>
   Cookie Remap <cookie_remap.en>
   ESI <esi.en>
   Escalate <escalate.en>
   Compress <compress.en>
   Generator <generator.en>
   Header Rewrite <header_rewrite.en>
   Health Checks <healthchecks.en>
   HTTP Stats <http_stats.en>
   JA3 Fingerprint <ja3_fingerprint.en>
   Lua <lua.en>
   Regex Remap <regex_remap.en>
   Regex Revalidate <regex_revalidate.en>
   Remap Purge <remap_purge.en>
   Remap Stats <remap_stats.en>
   Stats over HTTP <stats_over_http.en>
   TCPInfo <tcpinfo.en>
   Traffic Dump <traffic_dump.en>
   WebP Transform <webp_transform.en>
   XDebug <xdebug.en>

:doc:`AuthProxy <authproxy.en>`
   Delegates the authorization decision of a request to an external HTTP service.

:doc:`AWS S3 Authentication <s3_auth.en>`
   Support for Amazon S3 authentication features.

:doc:`Background Fetch <background_fetch.en>`
   Proactively fetch content from Origin in a way that it will fill the object into cache.

:doc:`Cache Key and Parent Selection URL Manipulation <cachekey.en>`
   Allows some common cache key or parent selection URL manipulations based on various HTTP request elements.

:doc:`Cache Promotion Policies <cache_promote.en>`
   Allows for control over which assets should be written to cache, or not.

:doc:`Cache Range Requests <cache_range_requests.en>`
   Cache ranges by adding the range request header to the cache key.

:doc:`Combo Handler <combo_handler.en>`
   Provides an intelligent way to combine multiple URLs into a single URL, and have Apache Traffic Server combine the components into one response.

:doc:`Configuration Remap <conf_remap.en>`
    Override configuration directives on a per-rule basis.

:doc:`ESI <esi.en>`
   Implements the Edge Side Includes (ESI) specification.

:doc:`Escalate <escalate.en>`
   Escalate: when the origin returns specific status codes, retry the request at a secondary origin (failover/fail-action)

:doc:`Generator <generator.en>`
   Generate arbitrary response data.

:doc:`Compress <compress.en>`
    Compress or deflate cache responses.

    .. sidebar: Formerly "gzip".

:doc:`Header Rewrite <header_rewrite.en>`
    Modify requests and responses based on incoming and outgoing headers and
    other transaction attributes.

:doc:`Health Checks <healthchecks.en>`
    Define service health check links.

:doc:`HTTP Stats <http_stats.en>`
    A remap-based plugin that provides an HTTP interface to all |TS| statistics.

:doc:`JA3 Fingerprint <ja3_fingerprint.en>`
   Calculates JA3 Fingerprints for incoming SSL traffic.

:doc:`Lua <lua.en>`
   Allows plugins to be written in Lua instead of C code.

:doc:`Regex Remap <regex_remap.en>`
    Configure remapping rules using regular expressions.

:doc:`Regex Revalidate <regex_revalidate.en>`
   Configurable rules for forcing cache object revalidations using regular expressions.

:doc:`Remap Stats <remap_stats.en>`
   This global plugin adds remap stats to the stats.

:doc:`Stats over HTTP <stats_over_http.en>`
    Provide an HTTP interface to all |TS| statistics.

:doc:`TCPInfo <tcpinfo.en>`
    Log TCP metrics at various points of the HTTP processing pipeline.

:doc:`Traffic Dump <traffic_dump.en>`
   Dumps traffic data into a JSON format file which can be used to replay traffic.

:doc:`WebP Transform <webp_transform.en>`
   Converts jpeg and png images to webp format.

:doc:`XDebug <xdebug.en>`
   Allows HTTP clients to debug the operation of the Traffic Server cache using the X-Debug header.

Experimental plugins
====================

Plugins that are considered experimental are located in the
`plugins/experimental <https://git-wip-us.apache.org/repos/asf?p=trafficserver.git;a=tree;f=plugins/experimental;hb=HEAD>`_
directory of the |TS| source tree. Experimental plugins can be compiled by passing the
`--enable-experimental-plugins` option to `configure`::

    $ autoconf -i
    $ ./configure --enable-experimental-plugins
    $ make

.. toctree::
   :hidden:

   Access Control <access_control.en>
   Block Errors <block_errors.en>
   Cache Fill <cache_fill.en>
   Certifier <certifier.en>
   Cert Reporting Tool <cert_reporting_tool.en>
   GeoIP ACL <geoip_acl.en>
   FQ Pacing <fq_pacing.en>
   Header Frequency <header_freq.en>
   Hook Trace <hook-trace.en>
   ICAP <icap.en>
   Maxmind ACL <maxmind_acl.en>
   Memcache <memcache.en>
   Memory Profile <memory_profile.en>
   Money Trace <money_trace.en>
   MP4 <mp4.en>
   Multiplexer <multiplexer.en>
   OpenTelemetry Tracer <otel_tracer.en>
   Rate Limit <rate_limit.en>
   URI Signing <uri_signing.en>
   Legacy Signed URLs <url_sig.en>
   Slice <slice.en>
   SSL Headers <sslheaders.en>
   SSL Session Reuse <ssl_session_reuse.en>
   STEK Share <stek_share.en>
   System Statistics <system_stats.en>
   Wasm <wasm.en>
   Prefetch <prefetch.en>

:doc:`Access Control <access_control.en>`
   Access control plugin that handles various access control use-cases.

:doc:`Block Errors <block_errors.en>`
   Blocks or downgrades new connections when the server receives too many errors from an IP address.

:doc:`Certifier <certifier.en>`
   Manages and/or generates certificates for incoming HTTPS requests.

:doc:`Cert Reporting Tool <cert_reporting_tool.en>`
   Examines and logs information on loaded certificates.

:doc:`FQ Pacing <fq_pacing.en>`
   FQ Pacing: Rate Limit TCP connections using Linux's Fair Queuing queue discipline

:doc:`GeoIP ACL <geoip_acl.en>`
   Deny or allow requests based on the source IP geo-location.

:doc:`Header Frequency <header_freq.en>`
   Count the frequency of headers.

:doc:`ICAP <icap.en>`
   Pass response data to external server for further processing using the ICAP protocol.

:doc:`MaxMind ACL <maxmind_acl.en>`
   ACL based on the maxmind geo databases (GeoIP2 mmdb and libmaxminddb)

:doc:`Memcache <memcache.en>`
   Implements the memcache protocol for cache contents.

:doc:`Money Trace <money_trace.en>`
   Allows Trafficserver to participate in a distributed tracing system based upon the Comcast Money library.

:doc:`MP4 <mp4.en>`
   MP4 streaming media.

:doc:`Multiplexer <multiplexer.en>`
   Multiplex inbound requests to multiple upstream destinations. This is useful for requests that
   are beacons or other metric gathering requests, to report to multiple upstreams. Alternatively
   this can be used to do A/B testing by sending a duplicated slice of inbound production traffic to
   experimental upstreams.

:doc:`OpenTelemetry Tracer <otel_tracer.en>`
   Allows Trafficserver to participate in OpenTelemetry distributed tracing system

:doc:`Prefetch <prefetch.en>`
   Pre-fetch objects based on the requested URL path pattern.

:doc:`Rate Limit <rate_limit.en>`
   Simple transaction rate limiting.

:doc:`Remap Purge <remap_purge.en>`
   This remap plugin allows the administrator to easily setup remotely
   controlled ``PURGE`` for the content of an entire remap rule.

:doc:`URI Signing <uri_signing.en>`
   Adds support for verifying URL signatures for incoming requests to either deny or redirect access,
   implementing the IETF URI Signing draft RFC.

:doc:`Legacy Signed URLs <url_sig.en>`
   Adds support for verifying URL signatures for incoming requests to either deny or redirect access.

   .. note::

    URL Sig is old and unlikely to be standardized. Prefer URI Signing.

:doc:`Slice <slice.en>`
   Slice full file or range based requests into deterministic chunks, allowing large files to be
   spread across multiple cache stripes. Allows arbitrary range requests to be satisfied by stitching
   these chunks together.

:doc:`SSL Session Reuse <ssl_session_reuse.en>`
   Coordinates Session ID and ticket based TLS session resumption between a group of ATS machines.

:doc:`SSL Headers <sslheaders.en>`
   Populate request headers with SSL session information.

:doc:`STEK Share <stek_share.en>`
    Coordinates STEK (Session Ticket Encryption Key) between ATS instances running in a group.

:doc:`System Stats <system_stats.en>`
    Inserts system statistics in to the stats list

:doc:`Wasm <wasm.en>`
   Allows WebAssembly/Wasm (proxy-wasm) module to be used as ATS Plugin.
