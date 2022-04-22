// **********************************************************************
// This file was generated by a TARS parser!
// TARS version 3.0.3.
// **********************************************************************

#ifndef __TRANSACTION_H_
#define __TRANSACTION_H_

#include <bcos-cpp-sdk/utilities/tx/tars/tup/Tars.h>
#include <bcos-cpp-sdk/utilities/tx/tars/tup/TarsJson.h>

#include <map>
#include <string>
#include <vector>
using namespace std;

#pragma GCC diagnostic ignored "-Wunused-parameter"

namespace bcostars
{
struct TransactionData : public tars::TarsStructBase
{
public:
    static string className() { return "bcostars.TransactionData"; }
    static string MD5() { return "ea41d47be6b852a5c3edcfe7a805be85"; }
    TransactionData() { resetDefautlt(); }
    void resetDefautlt()
    {
        version = 0;
        chainID = "";
        groupID = "";
        blockLimit = 0;
        nonce = "";
        to = "";
        input.clear();
        abi = "";
    }
    template <typename WriterT>
    void writeTo(tars::TarsOutputStream<WriterT>& _os) const
    {
        _os.write(version, 1);
        _os.write(chainID, 2);
        _os.write(groupID, 3);
        _os.write(blockLimit, 4);
        _os.write(nonce, 5);
        if (to != "")
        {
            _os.write(to, 6);
        }
        _os.write(input, 7);
        if (abi != "")
        {
            _os.write(abi, 8);
        }
    }
    template <typename ReaderT>
    void readFrom(tars::TarsInputStream<ReaderT>& _is)
    {
        resetDefautlt();
        _is.read(version, 1, true);
        _is.read(chainID, 2, true);
        _is.read(groupID, 3, true);
        _is.read(blockLimit, 4, true);
        _is.read(nonce, 5, true);
        _is.read(to, 6, false);
        _is.read(input, 7, true);
        _is.read(abi, 8, false);
    }
    tars::JsonValueObjPtr writeToJson() const
    {
        tars::JsonValueObjPtr p = new tars::JsonValueObj();
        p->value["version"] = tars::JsonOutput::writeJson(version);
        p->value["chainID"] = tars::JsonOutput::writeJson(chainID);
        p->value["groupID"] = tars::JsonOutput::writeJson(groupID);
        p->value["blockLimit"] = tars::JsonOutput::writeJson(blockLimit);
        p->value["nonce"] = tars::JsonOutput::writeJson(nonce);
        p->value["to"] = tars::JsonOutput::writeJson(to);
        p->value["input"] = tars::JsonOutput::writeJson(input);
        p->value["abi"] = tars::JsonOutput::writeJson(abi);
        return p;
    }
    string writeToJsonString() const { return tars::TC_Json::writeValue(writeToJson()); }
    void readFromJson(const tars::JsonValuePtr& p, bool isRequire = true)
    {
        resetDefautlt();
        if (NULL == p.get() || p->getType() != tars::eJsonTypeObj)
        {
            char s[128];
            snprintf(s, sizeof(s), "read 'struct' type mismatch, get type: %d.",
                (p.get() ? p->getType() : 0));
            throw tars::TC_Json_Exception(s);
        }
        tars::JsonValueObjPtr pObj = tars::JsonValueObjPtr::dynamicCast(p);
        tars::JsonInput::readJson(version, pObj->value["version"], true);
        tars::JsonInput::readJson(chainID, pObj->value["chainID"], true);
        tars::JsonInput::readJson(groupID, pObj->value["groupID"], true);
        tars::JsonInput::readJson(blockLimit, pObj->value["blockLimit"], true);
        tars::JsonInput::readJson(nonce, pObj->value["nonce"], true);
        tars::JsonInput::readJson(to, pObj->value["to"], false);
        tars::JsonInput::readJson(input, pObj->value["input"], true);
        tars::JsonInput::readJson(abi, pObj->value["abi"], false);
    }
    void readFromJsonString(const string& str) { readFromJson(tars::TC_Json::getValue(str)); }
    ostream& display(ostream& _os, int _level = 0) const
    {
        tars::TarsDisplayer _ds(_os, _level);
        _ds.display(version, "version");
        _ds.display(chainID, "chainID");
        _ds.display(groupID, "groupID");
        _ds.display(blockLimit, "blockLimit");
        _ds.display(nonce, "nonce");
        _ds.display(to, "to");
        _ds.display(input, "input");
        _ds.display(abi, "abi");
        return _os;
    }
    ostream& displaySimple(ostream& _os, int _level = 0) const
    {
        tars::TarsDisplayer _ds(_os, _level);
        _ds.displaySimple(version, true);
        _ds.displaySimple(chainID, true);
        _ds.displaySimple(groupID, true);
        _ds.displaySimple(blockLimit, true);
        _ds.displaySimple(nonce, true);
        _ds.displaySimple(to, true);
        _ds.displaySimple(input, true);
        _ds.displaySimple(abi, false);
        return _os;
    }

public:
    tars::Int32 version;
    std::string chainID;
    std::string groupID;
    tars::Int64 blockLimit;
    std::string nonce;
    std::string to;
    vector<tars::Char> input;
    std::string abi;
};
inline bool operator==(const TransactionData& l, const TransactionData& r)
{
    return l.version == r.version && l.chainID == r.chainID && l.groupID == r.groupID &&
           l.blockLimit == r.blockLimit && l.nonce == r.nonce && l.to == r.to &&
           l.input == r.input && l.abi == r.abi;
}
inline bool operator!=(const TransactionData& l, const TransactionData& r)
{
    return !(l == r);
}
inline ostream& operator<<(ostream& os, const TransactionData& r)
{
    os << r.writeToJsonString();
    return os;
}
inline istream& operator>>(istream& is, TransactionData& l)
{
    std::istreambuf_iterator<char> eos;
    std::string s(std::istreambuf_iterator<char>(is), eos);
    l.readFromJsonString(s);
    return is;
}

struct Transaction : public tars::TarsStructBase
{
public:
    static string className() { return "bcostars.Transaction"; }
    static string MD5() { return "ad46f3dbb0da87bdc5ed991eb2a8caff"; }
    Transaction() { resetDefautlt(); }
    void resetDefautlt()
    {
        data.resetDefautlt();
        dataHash.clear();
        signature.clear();
        importTime = 0;
        attribute = 0;
        source = "";
        sender.clear();
    }
    template <typename WriterT>
    void writeTo(tars::TarsOutputStream<WriterT>& _os) const
    {
        _os.write(data, 1);
        if (dataHash.size() > 0)
        {
            _os.write(dataHash, 2);
        }
        if (signature.size() > 0)
        {
            _os.write(signature, 3);
        }
        if (importTime != 0)
        {
            _os.write(importTime, 4);
        }
        if (attribute != 0)
        {
            _os.write(attribute, 5);
        }
        if (source != "")
        {
            _os.write(source, 6);
        }
        if (sender.size() > 0)
        {
            _os.write(sender, 7);
        }
    }
    template <typename ReaderT>
    void readFrom(tars::TarsInputStream<ReaderT>& _is)
    {
        resetDefautlt();
        _is.read(data, 1, false);
        _is.read(dataHash, 2, false);
        _is.read(signature, 3, false);
        _is.read(importTime, 4, false);
        _is.read(attribute, 5, false);
        _is.read(source, 6, false);
        _is.read(sender, 7, false);
    }
    tars::JsonValueObjPtr writeToJson() const
    {
        tars::JsonValueObjPtr p = new tars::JsonValueObj();
        p->value["data"] = tars::JsonOutput::writeJson(data);
        p->value["dataHash"] = tars::JsonOutput::writeJson(dataHash);
        p->value["signature"] = tars::JsonOutput::writeJson(signature);
        p->value["importTime"] = tars::JsonOutput::writeJson(importTime);
        p->value["attribute"] = tars::JsonOutput::writeJson(attribute);
        p->value["source"] = tars::JsonOutput::writeJson(source);
        p->value["sender"] = tars::JsonOutput::writeJson(sender);
        return p;
    }
    string writeToJsonString() const { return tars::TC_Json::writeValue(writeToJson()); }
    void readFromJson(const tars::JsonValuePtr& p, bool isRequire = true)
    {
        resetDefautlt();
        if (NULL == p.get() || p->getType() != tars::eJsonTypeObj)
        {
            char s[128];
            snprintf(s, sizeof(s), "read 'struct' type mismatch, get type: %d.",
                (p.get() ? p->getType() : 0));
            throw tars::TC_Json_Exception(s);
        }
        tars::JsonValueObjPtr pObj = tars::JsonValueObjPtr::dynamicCast(p);
        tars::JsonInput::readJson(data, pObj->value["data"], false);
        tars::JsonInput::readJson(dataHash, pObj->value["dataHash"], false);
        tars::JsonInput::readJson(signature, pObj->value["signature"], false);
        tars::JsonInput::readJson(importTime, pObj->value["importTime"], false);
        tars::JsonInput::readJson(attribute, pObj->value["attribute"], false);
        tars::JsonInput::readJson(source, pObj->value["source"], false);
        tars::JsonInput::readJson(sender, pObj->value["sender"], false);
    }
    void readFromJsonString(const string& str) { readFromJson(tars::TC_Json::getValue(str)); }
    ostream& display(ostream& _os, int _level = 0) const
    {
        tars::TarsDisplayer _ds(_os, _level);
        _ds.display(data, "data");
        _ds.display(dataHash, "dataHash");
        _ds.display(signature, "signature");
        _ds.display(importTime, "importTime");
        _ds.display(attribute, "attribute");
        _ds.display(source, "source");
        _ds.display(sender, "sender");
        return _os;
    }
    ostream& displaySimple(ostream& _os, int _level = 0) const
    {
        tars::TarsDisplayer _ds(_os, _level);
        _ds.displaySimple(data, true);
        _ds.displaySimple(dataHash, true);
        _ds.displaySimple(signature, true);
        _ds.displaySimple(importTime, true);
        _ds.displaySimple(attribute, true);
        _ds.displaySimple(source, true);
        _ds.displaySimple(sender, false);
        return _os;
    }

public:
    bcostars::TransactionData data;
    vector<tars::Char> dataHash;
    vector<tars::Char> signature;
    tars::Int64 importTime;
    tars::Int32 attribute;
    std::string source;
    vector<tars::Char> sender;
};
inline bool operator==(const Transaction& l, const Transaction& r)
{
    return l.data == r.data && l.dataHash == r.dataHash && l.signature == r.signature &&
           l.importTime == r.importTime && l.attribute == r.attribute && l.source == r.source &&
           l.sender == r.sender;
}
inline bool operator!=(const Transaction& l, const Transaction& r)
{
    return !(l == r);
}
inline ostream& operator<<(ostream& os, const Transaction& r)
{
    os << r.writeToJsonString();
    return os;
}
inline istream& operator>>(istream& is, Transaction& l)
{
    std::istreambuf_iterator<char> eos;
    std::string s(std::istreambuf_iterator<char>(is), eos);
    l.readFromJsonString(s);
    return is;
}

using TransactionDataPtr = std::shared_ptr<TransactionData>;
using TransactionDataUniquePtr = std::unique_ptr<TransactionData>;
using TransactionDataConstPtr = std::shared_ptr<const TransactionData>;
using TransactionPtr = std::shared_ptr<Transaction>;
using TransactionUniquePtr = std::unique_ptr<Transaction>;
using TransactionConstPtr = std::shared_ptr<const Transaction>;

}  // namespace bcostars


#endif
