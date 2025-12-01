/*
 * Copyright (C) 2021-2025, Dylan Liu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

/**
 * @file new_audit_strategy.cpp
 * @brief include the class of the simple static audit strategy
 * @details include the class of the simple static audit strategy
 * @author Dylan Liu
 * @version 1.0.0
 * @date 2025-10-28
 * @copyright Copyright (C) 2021 - 2025, Dylan Liu
 */

#include "NewAuditStrategy/new_audit_strategy.h"
#include "AuditEngineLib/strategies/crypto/sm9_strategy.h"

#include <iostream>
using namespace std;
using namespace DIAS::Interfaces::Audit;
using namespace DIAS::Algorithms::Crypto::SM9;

namespace DIAS::Algorithms::Audit::NewAuditStrategy {

NewAuditStrategy::NewAuditStrategy()
{
    _algorithm = make_shared<SM9Algorithm>();
    _crypto_strategy = make_shared<SM9CryptoStrategy>();
    _algorithm->setCryptoStrategy(_crypto_strategy);
}

void NewAuditStrategy::setAlgorithm(const CryptoAlgorithmPtr& algorithm)
{
    _algorithm = algorithm;
    _algorithm->setCryptoStrategy(_crypto_strategy);
}

void NewAuditStrategy::setAlgoStrategy(const shared_ptr<CryptoStrategy>& strategy)
{
    _crypto_strategy = strategy;
}

AuditDataPackPtr NewAuditStrategy::algoInit(const AuditDataPackPtr& input)
{
    AuditDataPackPtr output = make_shared<AuditDataPack>();
    return output;
}

AuditDataPackPtr NewAuditStrategy::dataIng(const AuditDataPackPtr& input)
{
    AuditDataPackPtr output = make_shared<AuditDataPack>();
    return output;
}

TagPtr NewAuditStrategy::tagGen(AuditArray& data, const CryptoPack& params)
{
    return nullptr;
}

AuditDataPackPtr NewAuditStrategy::tagsGen(const AuditDataPackPtr& input)
{
    AuditDataPackPtr output = make_shared<AuditDataPack>();
    return output;
}

AuditDataPackPtr NewAuditStrategy::maintaince(const AuditDataPackPtr& input)
{
    AuditDataPackPtr output = make_shared<AuditDataPack>();
    return output;
}

AuditDataPackPtr NewAuditStrategy::chlgGen(const AuditDataPackPtr& input)
{
    AuditDataPackPtr output = make_shared<AuditDataPack>();
    return output;
}

AuditDataPackPtr NewAuditStrategy::prvGen(const AuditDataPackPtr& input)
{
    AuditDataPackPtr output = make_shared<AuditDataPack>();
    return output;
}

bool NewAuditStrategy::prvVerify(const AuditDataPackPtr& input)
{
    return false;
}

}
