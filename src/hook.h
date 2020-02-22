// Copyright (c) 2010-2011 Vincent Durham
// Distributed under the MIT/X11 software license, see the accompanying
// file license.txt or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_HOOKS_H
#define BITCOIN_HOOKS_H

#include <string>

class CTransaction;
class CBlockIndex;
class CScript;
class CTxOut;

class CHooks
{
public:
	virtual bool CheckTransaction(const CTransaction& tx) = 0;
    virtual bool ConnectInputs(const CTransaction& tx, CBlockIndex* pindexBlock, bool fBlock, bool fMiner) = 0;
    virtual bool DisconnectInputs (const CTransaction& tx, CBlockIndex* pindexBlock) = 0;
    virtual bool ExtractAddress(const CScript& script, std::string& address) = 0;
    virtual std::string IrcPrefix() = 0;
    virtual bool AcceptToMemoryPool(const CTransaction& tx) = 0;
    virtual void RemoveFromMemoryPool(const CTransaction& tx) = 0;

    /* These are for display and wallet management purposes.  Not for use to decide
     * whether to spend a coin. */
    virtual bool IsMine(const CTransaction& tx) = 0;
    virtual bool IsMine(const CTransaction& tx, const CTxOut& txout, bool ignore_name_new = false) = 0;
};

extern CHooks* InitHook();
#endif
