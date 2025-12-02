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
 * @file new_audit_strategy.h
 * @brief Provides new audit algorithms and related strategies.
 * @details This file defines constants, tags, challenges, proofs, and audit strategies
 *          under the namespace DIAS::Algorithms::Audit::NewAuditStrategy.
 * @author Dylan Liu
 * @version 1.0.0
 * @date 2025-12-01
 * @copyright Copyright (C) 2021 - 2025, Dylan Liu
 */

#ifndef NEW_AUDIT_STRATEGY_H
#define NEW_AUDIT_STRATEGY_H

#include "AuditEngineLib/algorithms/crypto/sm9.h"
#include "AuditEngineLib/interfaces/audit/audit_strategy.h"
#include <random>
#include <set>

using namespace DIAS::Interfaces::Audit;

/**
 * @namespace DIAS::Algorithms::Audit::AuditStrategy
 * @brief Provides new audit algorithms and related constants.
 */
namespace DIAS::Algorithms::Audit::NewAuditStrategy {

const size_t fileBlockSize = 1024; /**< Constant representing the block size used for file operations (in bytes). */
const size_t segmentSize   = sizeof(sm9_z256_t); /**< Constant representing the segment size based on sm9_z256_t type (in bytes). */

/**
 * @class NewAuditStrategy
 * @brief Implements the new audit strategy for audits.
 */
class NewAuditStrategy : public AuditStrategy {
public:
    /**
     * @brief Constructs the audit strategy.
     */
    NewAuditStrategy();

    /**
     * @brief Returns the name of the strategy.
     *
     * @return string, Name of the strategy.
     */
    string name() const override { return "new"; }

    /**
     * @brief Returns the version of the strategy.
     *
     * @return string, Version string.
     */
    string version() const override { return "1.0"; }

    /**
     * @brief Returns the capabilities of the strategy.
     *
     * @return Capabilities, Supported capabilities.
     */
    Capabilities caps() const override { return Capabilities::BatchVerify; }

    /**
     * @brief Sets the cryptographic algorithm.
     *
     * @param algorithm [IN] Cryptographic algorithm pointer.
     */
    void setAlgorithm(const CryptoAlgorithmPtr& algorithm) override;

    /**
     * @brief Sets the cryptographic strategy.
     *
     * @param strategy [IN] Shared pointer to cryptographic strategy.
     */
    void setAlgoStrategy(const shared_ptr<CryptoStrategy>& strategy) override;

    /**
     * @brief Initializes the algorithm with input data.
     *
     * @param input [IN] Input data pack.
     * @return AuditDataPackPtr, Initialized data pack.
     */
    AuditDataPackPtr algoInit(const AuditDataPackPtr& input) override;

    /**
     * @brief Processes input data.
     *
     * @param input [IN] Input data pack.
     * @return AuditDataPackPtr, Processed data pack.
     */
    AuditDataPackPtr dataIng(const AuditDataPackPtr& input) override;

    /**
     * @brief Generates tags from input data.
     *
     * @param input [IN] Input data pack.
     * @return AuditDataPackPtr, Generated tags data pack.
     */
    AuditDataPackPtr tagsGen(const AuditDataPackPtr& input) override;

    /**
     * @brief Maintains audit data (not supported).
     *
     * @param input [IN] Input data pack.
     * @return AuditDataPackPtr, Throws logic_error.
     */
    AuditDataPackPtr maintaince(const AuditDataPackPtr& input) override;

    /**
     * @brief Generates challenges from input data.
     *
     * @param input [IN] Input data pack.
     * @return AuditDataPackPtr, Generated challenges data pack.
     */
    AuditDataPackPtr chlgGen(const AuditDataPackPtr& input) override;

    /**
     * @brief Generates proofs from input data.
     *
     * @param input [IN] Input data pack.
     * @return AuditDataPackPtr, Generated proofs data pack.
     */
    AuditDataPackPtr prvGen(const AuditDataPackPtr& input) override;

    /**
     * @brief Verifies proofs from input data.
     *
     * @param input [IN] Input data pack.
     * @return bool, True if verification succeeds, false otherwise.
     */
    bool prvVerify(const AuditDataPackPtr& input) override;

    static AuditStrategy* create(){
        return new NewAuditStrategy();
    }

protected:
    /**
     * @brief Generates a tag from data and cryptographic parameters.
     *
     * @param data [IN] Input audit data array.
     * @param params [IN] Cryptographic parameters.
     * @return TagPtr, Generated tag.
     */
    TagPtr tagGen(AuditArray& data, const CryptoPack& params);

    CryptoAlgorithmPtr _algorithm; /**< Pointer to the cryptographic algorithm used in the strategy. */
    shared_ptr<CryptoStrategy> _crypto_strategy; /**< Shared pointer to the cryptographic strategy implementation. */
};

extern "C" AuditStrategy* create_audit_strategy(){
    return NewAuditStrategy::create();
}

} // namespace DIAS::Algorithms::Audit::NewAuditStrategy

#endif // NEW_AUDIT_STRATEGY_H