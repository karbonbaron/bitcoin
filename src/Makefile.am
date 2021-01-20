# Copyright (c) 2013-2016 The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

DIST_SUBDIRS = secp256k1 univalue

AM_LDFLAGS = $(LIBTOOL_LDFLAGS) $(HARDENED_LDFLAGS) $(GPROF_LDFLAGS) $(SANITIZER_LDFLAGS)
AM_CXXFLAGS = $(DEBUG_CXXFLAGS) $(HARDENED_CXXFLAGS) $(WARN_CXXFLAGS) $(NOWARN_CXXFLAGS) $(ERROR_CXXFLAGS) $(GPROF_CXXFLAGS) $(SANITIZER_CXXFLAGS)
AM_CPPFLAGS = $(DEBUG_CPPFLAGS) $(HARDENED_CPPFLAGS)
AM_LIBTOOLFLAGS = --preserve-dup-deps
PTHREAD_FLAGS = $(PTHREAD_CFLAGS) $(PTHREAD_LIBS)
EXTRA_LIBRARIES =

if EMBEDDED_UNIVALUE
LIBUNIVALUE = univalue/libunivalue.la

$(LIBUNIVALUE): $(wildcard univalue/lib/*) $(wildcard univalue/include/*)
	$(AM_V_at)$(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)
else
LIBUNIVALUE = $(UNIVALUE_LIBS)
endif

MONICOIN_INCLUDES=-I$(builddir) -I$(srcdir)/secp256k1/include $(BDB_CPPFLAGS) $(BOOST_CPPFLAGS) $(LEVELDB_CPPFLAGS)

MONICOIN_INCLUDES += $(UNIVALUE_CFLAGS)

LIBMONICOIN_SERVER=libmonicoin_server.a
LIBMONICOIN_COMMON=libmonicoin_common.a
LIBMONICOIN_CONSENSUS=libmonicoin_consensus.a
LIBMONICOIN_CLI=libmonicoin_cli.a
LIBMONICOIN_UTIL=libmonicoin_util.a
LIBMONICOIN_CRYPTO_BASE=crypto/libmonicoin_crypto_base.a
LIBMONICOINQT=qt/libmonicoinqt.a
LIBSECP256K1=secp256k1/libsecp256k1.la

if ENABLE_ZMQ
LIBMONICOIN_ZMQ=libmonicoin_zmq.a
endif
if BUILD_MONICOIN_LIBS
LIBMONICOINCONSENSUS=libmonicoinconsensus.la
endif
if ENABLE_WALLET
LIBMONICOIN_WALLET=libmonicoin_wallet.a
LIBMONICOIN_WALLET_TOOL=libmonicoin_wallet_tool.a
endif

LIBMONICOIN_CRYPTO= $(LIBMONICOIN_CRYPTO_BASE)
if ENABLE_SSE41
LIBMONICOIN_CRYPTO_SSE41 = crypto/libmonicoin_crypto_sse41.a
LIBMONICOIN_CRYPTO += $(LIBMONICOIN_CRYPTO_SSE41)
endif
if ENABLE_AVX2
LIBMONICOIN_CRYPTO_AVX2 = crypto/libmonicoin_crypto_avx2.a
LIBMONICOIN_CRYPTO += $(LIBMONICOIN_CRYPTO_AVX2)
endif
if ENABLE_SHANI
LIBMONICOIN_CRYPTO_SHANI = crypto/libmonicoin_crypto_shani.a
LIBMONICOIN_CRYPTO += $(LIBMONICOIN_CRYPTO_SHANI)
endif

$(LIBSECP256K1): $(wildcard secp256k1/src/*.h) $(wildcard secp256k1/src/*.c) $(wildcard secp256k1/include/*)
	$(AM_V_at)$(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)

# Make is not made aware of per-object dependencies to avoid limiting building parallelization
# But to build the less dependent modules first, we manually select their order here:
EXTRA_LIBRARIES += \
  $(LIBMONICOIN_CRYPTO) \
  $(LIBMONICOIN_UTIL) \
  $(LIBMONICOIN_COMMON) \
  $(LIBMONICOIN_CONSENSUS) \
  $(LIBMONICOIN_SERVER) \
  $(LIBMONICOIN_CLI) \
  $(LIBMONICOIN_WALLET) \
  $(LIBMONICOIN_WALLET_TOOL) \
  $(LIBMONICOIN_ZMQ)

lib_LTLIBRARIES = $(LIBMONICOINCONSENSUS)

bin_PROGRAMS =
noinst_PROGRAMS =
TESTS =
BENCHMARKS =

if BUILD_MONICOIND
  bin_PROGRAMS += monicoind
endif

if BUILD_MONICOIN_NODE
  bin_PROGRAMS += monicoin-node
endif

if BUILD_MONICOIN_CLI
  bin_PROGRAMS += monicoin-cli
endif

if BUILD_MONICOIN_TX
  bin_PROGRAMS += monicoin-tx
endif

if ENABLE_WALLET
if BUILD_MONICOIN_WALLET
  bin_PROGRAMS += monicoin-wallet
endif
endif

if BUILD_MONICOIN_UTIL
  bin_PROGRAMS += monicoin-util
endif

.PHONY: FORCE check-symbols check-security
# monicoin core #
MONICOIN_CORE_H = \
  addrdb.h \
  addrman.h \
  attributes.h \
  banman.h \
  base58.h \
  bech32.h \
  blockencodings.h \
  blockfilter.h \
  bloom.h \
  chain.h \
  chainparams.h \
  chainparamsbase.h \
  chainparamsseeds.h \
  checkqueue.h \
  clientversion.h \
  coins.h \
  compat.h \
  compat/assumptions.h \
  compat/byteswap.h \
  compat/cpuid.h \
  compat/endian.h \
  compat/sanity.h \
  compressor.h \
  consensus/consensus.h \
  consensus/tx_check.h \
  consensus/tx_verify.h \
  core_io.h \
  core_memusage.h \
  cuckoocache.h \
  dbwrapper.h \
  flatfile.h \
  fs.h \
  httprpc.h \
  httpserver.h \
  index/base.h \
  index/blockfilterindex.h \
  index/disktxpos.h \
  index/txindex.h \
  indirectmap.h \
  init.h \
  interfaces/chain.h \
  interfaces/handler.h \
  interfaces/node.h \
  interfaces/wallet.h \
  key.h \
  key_io.h \
  logging.h \
  logging/timer.h \
  mapport.h \
  memusage.h \
  merkleblock.h \
  miner.h \
  net.h \
  net_permissions.h \
  net_processing.h \
  net_types.h \
  netaddress.h \
  netbase.h \
  netmessagemaker.h \
  node/coin.h \
  node/coinstats.h \
  node/context.h \
  node/psbt.h \
  node/transaction.h \
  node/ui_interface.h \
  node/utxo_snapshot.h \
  noui.h \
  optional.h \
  outputtype.h \
  policy/feerate.h \
  policy/fees.h \
  policy/policy.h \
  policy/rbf.h \
  policy/settings.h \
  pow.h \
  protocol.h \
  psbt.h \
  random.h \
  randomenv.h \
  reverse_iterator.h \
  rpc/blockchain.h \
  rpc/client.h \
  rpc/mining.h \
  rpc/protocol.h \
  rpc/rawtransaction_util.h \
  rpc/register.h \
  rpc/request.h \
  rpc/server.h \
  rpc/util.h \
  scheduler.h \
  script/descriptor.h \
  script/keyorigin.h \
  script/sigcache.h \
  script/sign.h \
  script/signingprovider.h \
  script/standard.h \
  shutdown.h \
  signet.h \
  streams.h \
  support/allocators/secure.h \
  support/allocators/zeroafterfree.h \
  support/cleanse.h \
  support/events.h \
  support/lockedpool.h \
  sync.h \
  threadinterrupt.h \
  threadsafety.h \
  timedata.h \
  torcontrol.h \
  txdb.h \
  txrequest.h \
  txmempool.h \
  undo.h \
  util/asmap.h \
  util/bip32.h \
  util/bytevectorhash.h \
  util/check.h \
  util/error.h \
  util/fees.h \
  util/golombrice.h \
  util/macros.h \
  util/memory.h \
  util/message.h \
  util/moneystr.h \
  util/rbf.h \
  util/ref.h \
  util/settings.h \
  util/spanparsing.h \
  util/string.h \
  util/system.h \
  util/threadnames.h \
  util/time.h \
  util/translation.h \
  util/ui_change_type.h \
  util/url.h \
  util/vector.h \
  validation.h \
  validationinterface.h \
  versionbits.h \
  versionbitsinfo.h \
  wallet/bdb.h \
  wallet/coincontrol.h \
  wallet/coinselection.h \
  wallet/context.h \
  wallet/crypter.h \
  wallet/db.h \
  wallet/dump.h \
  wallet/feebumper.h \
  wallet/fees.h \
  wallet/ismine.h \
  wallet/load.h \
  wallet/rpcwallet.h \
  wallet/salvage.h \
  wallet/scriptpubkeyman.h \
  wallet/sqlite.h \
  wallet/wallet.h \
  wallet/walletdb.h \
  wallet/wallettool.h \
  wallet/walletutil.h \
  walletinitinterface.h \
  warnings.h \
  zmq/zmqabstractnotifier.h \
  zmq/zmqnotificationinterface.h \
  zmq/zmqpublishnotifier.h \
  zmq/zmqrpc.h \
  zmq/zmqutil.h


obj/build.h: FORCE
	@$(MKDIR_P) $(builddir)/obj
	@$(top_srcdir)/share/genbuild.sh "$(abs_top_builddir)/src/obj/build.h" \
	  "$(abs_top_srcdir)"
libmonicoin_util_a-clientversion.$(OBJEXT): obj/build.h

# server: shared between monicoind and monicoin-qt
# Contains code accessing mempool and chain state that is meant to be separated
# from wallet and gui code (see node/README.md). Shared code should go in
# libmonicoin_common or libmonicoin_util libraries, instead.
libmonicoin_server_a_CPPFLAGS = $(AM_CPPFLAGS) $(MONICOIN_INCLUDES) $(MINIUPNPC_CPPFLAGS) $(EVENT_CFLAGS) $(EVENT_PTHREADS_CFLAGS)
libmonicoin_server_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libmonicoin_server_a_SOURCES = \
  addrdb.cpp \
  addrman.cpp \
  banman.cpp \
  blockencodings.cpp \
  blockfilter.cpp \
  chain.cpp \
  consensus/tx_verify.cpp \
  dbwrapper.cpp \
  flatfile.cpp \
  httprpc.cpp \
  httpserver.cpp \
  index/base.cpp \
  index/blockfilterindex.cpp \
  index/txindex.cpp \
  init.cpp \
  mapport.cpp \
  miner.cpp \
  net.cpp \
  net_processing.cpp \
  node/coin.cpp \
  node/coinstats.cpp \
  node/context.cpp \
  node/interfaces.cpp \
  node/psbt.cpp \
  node/transaction.cpp \
  node/ui_interface.cpp \
  noui.cpp \
  policy/fees.cpp \
  policy/rbf.cpp \
  policy/settings.cpp \
  pow.cpp \
  rest.cpp \
  rpc/blockchain.cpp \
  rpc/mining.cpp \
  rpc/misc.cpp \
  rpc/net.cpp \
  rpc/rawtransaction.cpp \
  rpc/server.cpp \
  script/sigcache.cpp \
  shutdown.cpp \
  signet.cpp \
  timedata.cpp \
  torcontrol.cpp \
  txdb.cpp \
  txrequest.cpp \
  txmempool.cpp \
  validation.cpp \
  validationinterface.cpp \
  versionbits.cpp \
  $(MONICOIN_CORE_H)

if ENABLE_WALLET
libmonicoin_server_a_SOURCES += wallet/init.cpp
endif
if !ENABLE_WALLET
libmonicoin_server_a_SOURCES += dummywallet.cpp
endif

if ENABLE_ZMQ
libmonicoin_zmq_a_CPPFLAGS = $(AM_CPPFLAGS) $(MONICOIN_INCLUDES) $(ZMQ_CFLAGS)
libmonicoin_zmq_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libmonicoin_zmq_a_SOURCES = \
  zmq/zmqabstractnotifier.cpp \
  zmq/zmqnotificationinterface.cpp \
  zmq/zmqpublishnotifier.cpp \
  zmq/zmqrpc.cpp \
  zmq/zmqutil.cpp
endif


# wallet: shared between monicoind and monicoin-qt, but only linked
# when wallet enabled
libmonicoin_wallet_a_CPPFLAGS = $(AM_CPPFLAGS) $(MONICOIN_INCLUDES) $(SQLITE_CFLAGS)
libmonicoin_wallet_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libmonicoin_wallet_a_SOURCES = \
  wallet/coincontrol.cpp \
  wallet/context.cpp \
  wallet/crypter.cpp \
  wallet/db.cpp \
  wallet/dump.cpp \
  wallet/feebumper.cpp \
  wallet/fees.cpp \
  wallet/interfaces.cpp \
  wallet/load.cpp \
  wallet/rpcdump.cpp \
  wallet/rpcwallet.cpp \
  wallet/scriptpubkeyman.cpp \
  wallet/wallet.cpp \
  wallet/walletdb.cpp \
  wallet/walletutil.cpp \
  wallet/coinselection.cpp \
  $(MONICOIN_CORE_H)

if USE_SQLITE
libmonicoin_wallet_a_SOURCES += wallet/sqlite.cpp
endif
if USE_BDB
libmonicoin_wallet_a_SOURCES += wallet/bdb.cpp wallet/salvage.cpp
endif

libmonicoin_wallet_tool_a_CPPFLAGS = $(AM_CPPFLAGS) $(MONICOIN_INCLUDES)
libmonicoin_wallet_tool_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libmonicoin_wallet_tool_a_SOURCES = \
  wallet/wallettool.cpp \
  $(MONICOIN_CORE_H)

# crypto primitives library
crypto_libmonicoin_crypto_base_a_CPPFLAGS = $(AM_CPPFLAGS)
crypto_libmonicoin_crypto_base_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
crypto_libmonicoin_crypto_base_a_SOURCES = \
  crypto/aes.cpp \
  crypto/aes.h \
  crypto/chacha_poly_aead.h \
  crypto/chacha_poly_aead.cpp \
  crypto/chacha20.h \
  crypto/chacha20.cpp \
  crypto/common.h \
  crypto/hkdf_sha256_32.cpp \
  crypto/hkdf_sha256_32.h \
  crypto/hmac_sha256.cpp \
  crypto/hmac_sha256.h \
  crypto/hmac_sha512.cpp \
  crypto/hmac_sha512.h \
  crypto/poly1305.h \
  crypto/poly1305.cpp \
  crypto/muhash.h \
  crypto/muhash.cpp \
  crypto/ripemd160.cpp \
  crypto/ripemd160.h \
  crypto/sha1.cpp \
  crypto/sha1.h \
  crypto/sha256.cpp \
  crypto/sha256.h \
  crypto/sha3.cpp \
  crypto/sha3.h \
  crypto/sha512.cpp \
  crypto/sha512.h \
  crypto/siphash.cpp \
  crypto/siphash.h

if USE_ASM
crypto_libmonicoin_crypto_base_a_SOURCES += crypto/sha256_sse4.cpp
endif

crypto_libmonicoin_crypto_sse41_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
crypto_libmonicoin_crypto_sse41_a_CPPFLAGS = $(AM_CPPFLAGS)
crypto_libmonicoin_crypto_sse41_a_CXXFLAGS += $(SSE41_CXXFLAGS)
crypto_libmonicoin_crypto_sse41_a_CPPFLAGS += -DENABLE_SSE41
crypto_libmonicoin_crypto_sse41_a_SOURCES = crypto/sha256_sse41.cpp

crypto_libmonicoin_crypto_avx2_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
crypto_libmonicoin_crypto_avx2_a_CPPFLAGS = $(AM_CPPFLAGS)
crypto_libmonicoin_crypto_avx2_a_CXXFLAGS += $(AVX2_CXXFLAGS)
crypto_libmonicoin_crypto_avx2_a_CPPFLAGS += -DENABLE_AVX2
crypto_libmonicoin_crypto_avx2_a_SOURCES = crypto/sha256_avx2.cpp

crypto_libmonicoin_crypto_shani_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
crypto_libmonicoin_crypto_shani_a_CPPFLAGS = $(AM_CPPFLAGS)
crypto_libmonicoin_crypto_shani_a_CXXFLAGS += $(SHANI_CXXFLAGS)
crypto_libmonicoin_crypto_shani_a_CPPFLAGS += -DENABLE_SHANI
crypto_libmonicoin_crypto_shani_a_SOURCES = crypto/sha256_shani.cpp

# consensus: shared between all executables that validate any consensus rules.
libmonicoin_consensus_a_CPPFLAGS = $(AM_CPPFLAGS) $(MONICOIN_INCLUDES)
libmonicoin_consensus_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libmonicoin_consensus_a_SOURCES = \
  amount.h \
  arith_uint256.cpp \
  arith_uint256.h \
  consensus/merkle.cpp \
  consensus/merkle.h \
  consensus/params.h \
  consensus/tx_check.cpp \
  consensus/validation.h \
  hash.cpp \
  hash.h \
  prevector.h \
  primitives/block.cpp \
  primitives/block.h \
  primitives/transaction.cpp \
  primitives/transaction.h \
  pubkey.cpp \
  pubkey.h \
  script/monicoinconsensus.cpp \
  script/interpreter.cpp \
  script/interpreter.h \
  script/script.cpp \
  script/script.h \
  script/script_error.cpp \
  script/script_error.h \
  serialize.h \
  span.h \
  tinyformat.h \
  uint256.cpp \
  uint256.h \
  util/strencodings.cpp \
  util/strencodings.h \
  version.h

# common: shared between monicoind, and monicoin-qt and non-server tools
libmonicoin_common_a_CPPFLAGS = $(AM_CPPFLAGS) $(MONICOIN_INCLUDES)
libmonicoin_common_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libmonicoin_common_a_SOURCES = \
  base58.cpp \
  bech32.cpp \
  bloom.cpp \
  chainparams.cpp \
  coins.cpp \
  compressor.cpp \
  core_read.cpp \
  core_write.cpp \
  key.cpp \
  key_io.cpp \
  merkleblock.cpp \
  netaddress.cpp \
  netbase.cpp \
  net_permissions.cpp \
  outputtype.cpp \
  policy/feerate.cpp \
  policy/policy.cpp \
  protocol.cpp \
  psbt.cpp \
  rpc/rawtransaction_util.cpp \
  rpc/util.cpp \
  scheduler.cpp \
  script/descriptor.cpp \
  script/sign.cpp \
  script/signingprovider.cpp \
  script/standard.cpp \
  versionbitsinfo.cpp \
  warnings.cpp \
  $(MONICOIN_CORE_H)

# util: shared between all executables.
# This library *must* be included to make sure that the glibc
# backward-compatibility objects and their sanity checks are linked.
libmonicoin_util_a_CPPFLAGS = $(AM_CPPFLAGS) $(MONICOIN_INCLUDES)
libmonicoin_util_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libmonicoin_util_a_SOURCES = \
  support/lockedpool.cpp \
  chainparamsbase.cpp \
  clientversion.cpp \
  compat/glibc_sanity.cpp \
  compat/glibcxx_sanity.cpp \
  compat/strnlen.cpp \
  fs.cpp \
  interfaces/handler.cpp \
  logging.cpp \
  random.cpp \
  randomenv.cpp \
  rpc/request.cpp \
  support/cleanse.cpp \
  sync.cpp \
  threadinterrupt.cpp \
  util/asmap.cpp \
  util/bip32.cpp \
  util/bytevectorhash.cpp \
  util/error.cpp \
  util/fees.cpp \
  util/system.cpp \
  util/message.cpp \
  util/moneystr.cpp \
  util/rbf.cpp \
  util/settings.cpp \
  util/threadnames.cpp \
  util/spanparsing.cpp \
  util/strencodings.cpp \
  util/string.cpp \
  util/time.cpp \
  $(MONICOIN_CORE_H)

if USE_LIBEVENT
libmonicoin_util_a_SOURCES += util/url.cpp
endif

if GLIBC_BACK_COMPAT
libmonicoin_util_a_SOURCES += compat/glibc_compat.cpp
AM_LDFLAGS += $(COMPAT_LDFLAGS)
endif

# cli: shared between monicoin-cli and monicoin-qt
libmonicoin_cli_a_CPPFLAGS = $(AM_CPPFLAGS) $(MONICOIN_INCLUDES)
libmonicoin_cli_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libmonicoin_cli_a_SOURCES = \
  compat/stdin.h \
  compat/stdin.cpp \
  rpc/client.cpp \
  $(MONICOIN_CORE_H)

nodist_libmonicoin_util_a_SOURCES = $(srcdir)/obj/build.h
#

# monicoind & monicoin-node binaries #
monicoin_daemon_sources = monicoind.cpp
monicoin_bin_cppflags = $(AM_CPPFLAGS) $(MONICOIN_INCLUDES)
monicoin_bin_cxxflags = $(AM_CXXFLAGS) $(PIE_FLAGS)
monicoin_bin_ldflags = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS) $(PTHREAD_FLAGS)

if TARGET_WINDOWS
monicoin_daemon_sources += monicoind-res.rc
endif

monicoin_bin_ldadd = \
  $(LIBMONICOIN_WALLET) \
  $(LIBMONICOIN_COMMON) \
  $(LIBMONICOIN_UTIL) \
  $(LIBUNIVALUE) \
  $(LIBMONICOIN_ZMQ) \
  $(LIBMONICOIN_CONSENSUS) \
  $(LIBMONICOIN_CRYPTO) \
  $(LIBLEVELDB) \
  $(LIBLEVELDB_SSE42) \
  $(LIBMEMENV) \
  $(LIBSECP256K1)

monicoin_bin_ldadd += $(BOOST_LIBS) $(BDB_LIBS) $(MINIUPNPC_LIBS) $(NATPMP_LIBS) $(EVENT_PTHREADS_LIBS) $(EVENT_LIBS) $(ZMQ_LIBS) $(SQLITE_LIBS)

monicoind_SOURCES = $(monicoin_daemon_sources)
monicoind_CPPFLAGS = $(monicoin_bin_cppflags)
monicoind_CXXFLAGS = $(monicoin_bin_cxxflags)
monicoind_LDFLAGS = $(monicoin_bin_ldflags)
monicoind_LDADD = $(LIBMONICOIN_SERVER) $(monicoin_bin_ldadd)

monicoin_node_SOURCES = $(monicoin_daemon_sources)
monicoin_node_CPPFLAGS = $(monicoin_bin_cppflags)
monicoin_node_CXXFLAGS = $(monicoin_bin_cxxflags)
monicoin_node_LDFLAGS = $(monicoin_bin_ldflags)
monicoin_node_LDADD = $(LIBMONICOIN_SERVER) $(monicoin_bin_ldadd)

# monicoin-cli binary #
monicoin_cli_SOURCES = monicoin-cli.cpp
monicoin_cli_CPPFLAGS = $(AM_CPPFLAGS) $(MONICOIN_INCLUDES) $(EVENT_CFLAGS)
monicoin_cli_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
monicoin_cli_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS) $(PTHREAD_FLAGS)

if TARGET_WINDOWS
monicoin_cli_SOURCES += monicoin-cli-res.rc
endif

monicoin_cli_LDADD = \
  $(LIBMONICOIN_CLI) \
  $(LIBUNIVALUE) \
  $(LIBMONICOIN_UTIL) \
  $(LIBMONICOIN_CRYPTO)

monicoin_cli_LDADD += $(BOOST_LIBS) $(EVENT_LIBS)
#

# monicoin-tx binary #
monicoin_tx_SOURCES = monicoin-tx.cpp
monicoin_tx_CPPFLAGS = $(AM_CPPFLAGS) $(MONICOIN_INCLUDES)
monicoin_tx_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
monicoin_tx_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS) $(PTHREAD_FLAGS)

if TARGET_WINDOWS
monicoin_tx_SOURCES += monicoin-tx-res.rc
endif

monicoin_tx_LDADD = \
  $(LIBUNIVALUE) \
  $(LIBMONICOIN_COMMON) \
  $(LIBMONICOIN_UTIL) \
  $(LIBMONICOIN_CONSENSUS) \
  $(LIBMONICOIN_CRYPTO) \
  $(LIBSECP256K1)

monicoin_tx_LDADD += $(BOOST_LIBS)
#

# monicoin-wallet binary #
monicoin_wallet_SOURCES = monicoin-wallet.cpp
monicoin_wallet_CPPFLAGS = $(monicoin_bin_cppflags)
monicoin_wallet_CXXFLAGS = $(monicoin_bin_cxxflags)
monicoin_wallet_LDFLAGS = $(monicoin_bin_ldflags)
monicoin_wallet_LDADD = $(LIBMONICOIN_WALLET_TOOL) $(monicoin_bin_ldadd)

if TARGET_WINDOWS
monicoin_wallet_SOURCES += monicoin-wallet-res.rc
endif
#

# monicoin-util binary #
monicoin_util_SOURCES = monicoin-util.cpp
monicoin_util_CPPFLAGS = $(AM_CPPFLAGS) $(MONICOIN_INCLUDES)
monicoin_util_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
monicoin_util_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
monicoin_util_SOURCES += monicoin-util-res.rc
endif

monicoin_util_LDADD = \
  $(LIBMONICOIN_COMMON) \
  $(LIBMONICOIN_UTIL) \
  $(LIBUNIVALUE) \
  $(LIBMONICOIN_CONSENSUS) \
  $(LIBMONICOIN_CRYPTO) \
  $(LIBSECP256K1)

monicoin_util_LDADD += $(BOOST_LIBS)
#

# monicoinconsensus library #
if BUILD_MONICOIN_LIBS
include_HEADERS = script/monicoinconsensus.h
libmonicoinconsensus_la_SOURCES = support/cleanse.cpp $(crypto_libmonicoin_crypto_base_a_SOURCES) $(libmonicoin_consensus_a_SOURCES)

if GLIBC_BACK_COMPAT
  libmonicoinconsensus_la_SOURCES += compat/glibc_compat.cpp
endif

libmonicoinconsensus_la_LDFLAGS = $(AM_LDFLAGS) -no-undefined $(RELDFLAGS)
libmonicoinconsensus_la_LIBADD = $(LIBSECP256K1)
libmonicoinconsensus_la_CPPFLAGS = $(AM_CPPFLAGS) -I$(builddir)/obj -I$(srcdir)/secp256k1/include -DBUILD_MONICOIN_INTERNAL
libmonicoinconsensus_la_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)

endif
#

CTAES_DIST =  crypto/ctaes/bench.c
CTAES_DIST += crypto/ctaes/ctaes.c
CTAES_DIST += crypto/ctaes/ctaes.h
CTAES_DIST += crypto/ctaes/README.md
CTAES_DIST += crypto/ctaes/test.c

CLEANFILES = $(EXTRA_LIBRARIES)

CLEANFILES += *.gcda *.gcno
CLEANFILES += compat/*.gcda compat/*.gcno
CLEANFILES += consensus/*.gcda consensus/*.gcno
CLEANFILES += crc32c/src/*.gcda crc32c/src/*.gcno
CLEANFILES += crypto/*.gcda crypto/*.gcno
CLEANFILES += index/*.gcda index/*.gcno
CLEANFILES += interfaces/*.gcda interfaces/*.gcno
CLEANFILES += node/*.gcda node/*.gcno
CLEANFILES += policy/*.gcda policy/*.gcno
CLEANFILES += primitives/*.gcda primitives/*.gcno
CLEANFILES += rpc/*.gcda rpc/*.gcno
CLEANFILES += script/*.gcda script/*.gcno
CLEANFILES += support/*.gcda support/*.gcno
CLEANFILES += univalue/*.gcda univalue/*.gcno
CLEANFILES += util/*.gcda util/*.gcno
CLEANFILES += wallet/*.gcda wallet/*.gcno
CLEANFILES += wallet/test/*.gcda wallet/test/*.gcno
CLEANFILES += zmq/*.gcda zmq/*.gcno
CLEANFILES += obj/build.h

EXTRA_DIST = $(CTAES_DIST)


config/monicoin-config.h: config/stamp-h1
	@$(MAKE) -C $(top_builddir) $(subdir)/$(@)
config/stamp-h1: $(top_srcdir)/$(subdir)/config/monicoin-config.h.in $(top_builddir)/config.status
	$(AM_V_at)$(MAKE) -C $(top_builddir) $(subdir)/$(@)
$(top_srcdir)/$(subdir)/config/monicoin-config.h.in:  $(am__configure_deps)
	$(AM_V_at)$(MAKE) -C $(top_srcdir) $(subdir)/config/monicoin-config.h.in

clean-local:
	-$(MAKE) -C secp256k1 clean
	-$(MAKE) -C univalue clean
	-rm -f leveldb/*/*.gcda leveldb/*/*.gcno leveldb/helpers/memenv/*.gcda leveldb/helpers/memenv/*.gcno
	-rm -f config.h
	-rm -rf test/__pycache__

.rc.o:
	@test -f $(WINDRES)
	## FIXME: How to get the appropriate modulename_CPPFLAGS in here?
	$(AM_V_GEN) $(WINDRES) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(CPPFLAGS) -DWINDRES_PREPROC -i $< -o $@

check-symbols: $(bin_PROGRAMS)
if TARGET_DARWIN
	@echo "Checking macOS dynamic libraries..."
	$(AM_V_at) OTOOL=$(OTOOL) $(PYTHON) $(top_srcdir)/contrib/devtools/symbol-check.py $(bin_PROGRAMS)
endif

if TARGET_WINDOWS
	@echo "Checking Windows dynamic libraries..."
	$(AM_V_at) OBJDUMP=$(OBJDUMP) $(PYTHON) $(top_srcdir)/contrib/devtools/symbol-check.py $(bin_PROGRAMS)
endif

if GLIBC_BACK_COMPAT
	@echo "Checking glibc back compat..."
	$(AM_V_at) CPPFILT=$(CPPFILT) $(PYTHON) $(top_srcdir)/contrib/devtools/symbol-check.py $(bin_PROGRAMS)
endif

check-security: $(bin_PROGRAMS)
if HARDEN
	@echo "Checking binary security..."
	$(AM_V_at) OBJDUMP=$(OBJDUMP) OTOOL=$(OTOOL) $(PYTHON) $(top_srcdir)/contrib/devtools/security-check.py $(bin_PROGRAMS)
endif

if EMBEDDED_LEVELDB
include Makefile.crc32c.include
include Makefile.leveldb.include
endif

include Makefile.test_util.include
include Makefile.test_fuzz.include

if ENABLE_TESTS
include Makefile.test.include
endif

if ENABLE_BENCH
include Makefile.bench.include
endif

if ENABLE_QT
include Makefile.qt.include
endif

if ENABLE_QT_TESTS
include Makefile.qttest.include
endif
