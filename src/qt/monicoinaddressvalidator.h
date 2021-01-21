// Copyright (c) 2011-2020 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef MONICOIN_QT_MONICOINADDRESSVALIDATOR_H
#define MONICOIN_QT_MONICOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class MonicoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit MonicoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

/** Monicoin address widget validator, checks for a valid monicoin address.
 */
class MonicoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit MonicoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

#endif // MONICOIN_QT_MONICOINADDRESSVALIDATOR_H
