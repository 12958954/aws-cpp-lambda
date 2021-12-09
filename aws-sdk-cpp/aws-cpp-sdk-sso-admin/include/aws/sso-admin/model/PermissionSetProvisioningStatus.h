﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/sso-admin/SSOAdmin_EXPORTS.h>
#include <aws/sso-admin/model/StatusValues.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/DateTime.h>
#include <utility>

namespace Aws
{
namespace Utils
{
namespace Json
{
  class JsonValue;
  class JsonView;
} // namespace Json
} // namespace Utils
namespace SSOAdmin
{
namespace Model
{

  /**
   * <p>A structure that is used to provide the status of the provisioning operation
   * for a specified permission set.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/sso-admin-2020-07-20/PermissionSetProvisioningStatus">AWS
   * API Reference</a></p>
   */
  class AWS_SSOADMIN_API PermissionSetProvisioningStatus
  {
  public:
    PermissionSetProvisioningStatus();
    PermissionSetProvisioningStatus(Aws::Utils::Json::JsonView jsonValue);
    PermissionSetProvisioningStatus& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>The status of the permission set provisioning process.</p>
     */
    inline const StatusValues& GetStatus() const{ return m_status; }

    /**
     * <p>The status of the permission set provisioning process.</p>
     */
    inline bool StatusHasBeenSet() const { return m_statusHasBeenSet; }

    /**
     * <p>The status of the permission set provisioning process.</p>
     */
    inline void SetStatus(const StatusValues& value) { m_statusHasBeenSet = true; m_status = value; }

    /**
     * <p>The status of the permission set provisioning process.</p>
     */
    inline void SetStatus(StatusValues&& value) { m_statusHasBeenSet = true; m_status = std::move(value); }

    /**
     * <p>The status of the permission set provisioning process.</p>
     */
    inline PermissionSetProvisioningStatus& WithStatus(const StatusValues& value) { SetStatus(value); return *this;}

    /**
     * <p>The status of the permission set provisioning process.</p>
     */
    inline PermissionSetProvisioningStatus& WithStatus(StatusValues&& value) { SetStatus(std::move(value)); return *this;}


    /**
     * <p>The identifier for tracking the request operation that is generated by the
     * universally unique identifier (UUID) workflow.</p>
     */
    inline const Aws::String& GetRequestId() const{ return m_requestId; }

    /**
     * <p>The identifier for tracking the request operation that is generated by the
     * universally unique identifier (UUID) workflow.</p>
     */
    inline bool RequestIdHasBeenSet() const { return m_requestIdHasBeenSet; }

    /**
     * <p>The identifier for tracking the request operation that is generated by the
     * universally unique identifier (UUID) workflow.</p>
     */
    inline void SetRequestId(const Aws::String& value) { m_requestIdHasBeenSet = true; m_requestId = value; }

    /**
     * <p>The identifier for tracking the request operation that is generated by the
     * universally unique identifier (UUID) workflow.</p>
     */
    inline void SetRequestId(Aws::String&& value) { m_requestIdHasBeenSet = true; m_requestId = std::move(value); }

    /**
     * <p>The identifier for tracking the request operation that is generated by the
     * universally unique identifier (UUID) workflow.</p>
     */
    inline void SetRequestId(const char* value) { m_requestIdHasBeenSet = true; m_requestId.assign(value); }

    /**
     * <p>The identifier for tracking the request operation that is generated by the
     * universally unique identifier (UUID) workflow.</p>
     */
    inline PermissionSetProvisioningStatus& WithRequestId(const Aws::String& value) { SetRequestId(value); return *this;}

    /**
     * <p>The identifier for tracking the request operation that is generated by the
     * universally unique identifier (UUID) workflow.</p>
     */
    inline PermissionSetProvisioningStatus& WithRequestId(Aws::String&& value) { SetRequestId(std::move(value)); return *this;}

    /**
     * <p>The identifier for tracking the request operation that is generated by the
     * universally unique identifier (UUID) workflow.</p>
     */
    inline PermissionSetProvisioningStatus& WithRequestId(const char* value) { SetRequestId(value); return *this;}


    /**
     * <p>The identifier of the Amazon Web Services account from which to list the
     * assignments.</p>
     */
    inline const Aws::String& GetAccountId() const{ return m_accountId; }

    /**
     * <p>The identifier of the Amazon Web Services account from which to list the
     * assignments.</p>
     */
    inline bool AccountIdHasBeenSet() const { return m_accountIdHasBeenSet; }

    /**
     * <p>The identifier of the Amazon Web Services account from which to list the
     * assignments.</p>
     */
    inline void SetAccountId(const Aws::String& value) { m_accountIdHasBeenSet = true; m_accountId = value; }

    /**
     * <p>The identifier of the Amazon Web Services account from which to list the
     * assignments.</p>
     */
    inline void SetAccountId(Aws::String&& value) { m_accountIdHasBeenSet = true; m_accountId = std::move(value); }

    /**
     * <p>The identifier of the Amazon Web Services account from which to list the
     * assignments.</p>
     */
    inline void SetAccountId(const char* value) { m_accountIdHasBeenSet = true; m_accountId.assign(value); }

    /**
     * <p>The identifier of the Amazon Web Services account from which to list the
     * assignments.</p>
     */
    inline PermissionSetProvisioningStatus& WithAccountId(const Aws::String& value) { SetAccountId(value); return *this;}

    /**
     * <p>The identifier of the Amazon Web Services account from which to list the
     * assignments.</p>
     */
    inline PermissionSetProvisioningStatus& WithAccountId(Aws::String&& value) { SetAccountId(std::move(value)); return *this;}

    /**
     * <p>The identifier of the Amazon Web Services account from which to list the
     * assignments.</p>
     */
    inline PermissionSetProvisioningStatus& WithAccountId(const char* value) { SetAccountId(value); return *this;}


    /**
     * <p>The ARN of the permission set that is being provisioned. For more information
     * about ARNs, see <a href="/general/latest/gr/aws-arns-and-namespaces.html">Amazon
     * Resource Names (ARNs) and Amazon Web Services Service Namespaces</a> in the
     * <i>Amazon Web Services General Reference</i>.</p>
     */
    inline const Aws::String& GetPermissionSetArn() const{ return m_permissionSetArn; }

    /**
     * <p>The ARN of the permission set that is being provisioned. For more information
     * about ARNs, see <a href="/general/latest/gr/aws-arns-and-namespaces.html">Amazon
     * Resource Names (ARNs) and Amazon Web Services Service Namespaces</a> in the
     * <i>Amazon Web Services General Reference</i>.</p>
     */
    inline bool PermissionSetArnHasBeenSet() const { return m_permissionSetArnHasBeenSet; }

    /**
     * <p>The ARN of the permission set that is being provisioned. For more information
     * about ARNs, see <a href="/general/latest/gr/aws-arns-and-namespaces.html">Amazon
     * Resource Names (ARNs) and Amazon Web Services Service Namespaces</a> in the
     * <i>Amazon Web Services General Reference</i>.</p>
     */
    inline void SetPermissionSetArn(const Aws::String& value) { m_permissionSetArnHasBeenSet = true; m_permissionSetArn = value; }

    /**
     * <p>The ARN of the permission set that is being provisioned. For more information
     * about ARNs, see <a href="/general/latest/gr/aws-arns-and-namespaces.html">Amazon
     * Resource Names (ARNs) and Amazon Web Services Service Namespaces</a> in the
     * <i>Amazon Web Services General Reference</i>.</p>
     */
    inline void SetPermissionSetArn(Aws::String&& value) { m_permissionSetArnHasBeenSet = true; m_permissionSetArn = std::move(value); }

    /**
     * <p>The ARN of the permission set that is being provisioned. For more information
     * about ARNs, see <a href="/general/latest/gr/aws-arns-and-namespaces.html">Amazon
     * Resource Names (ARNs) and Amazon Web Services Service Namespaces</a> in the
     * <i>Amazon Web Services General Reference</i>.</p>
     */
    inline void SetPermissionSetArn(const char* value) { m_permissionSetArnHasBeenSet = true; m_permissionSetArn.assign(value); }

    /**
     * <p>The ARN of the permission set that is being provisioned. For more information
     * about ARNs, see <a href="/general/latest/gr/aws-arns-and-namespaces.html">Amazon
     * Resource Names (ARNs) and Amazon Web Services Service Namespaces</a> in the
     * <i>Amazon Web Services General Reference</i>.</p>
     */
    inline PermissionSetProvisioningStatus& WithPermissionSetArn(const Aws::String& value) { SetPermissionSetArn(value); return *this;}

    /**
     * <p>The ARN of the permission set that is being provisioned. For more information
     * about ARNs, see <a href="/general/latest/gr/aws-arns-and-namespaces.html">Amazon
     * Resource Names (ARNs) and Amazon Web Services Service Namespaces</a> in the
     * <i>Amazon Web Services General Reference</i>.</p>
     */
    inline PermissionSetProvisioningStatus& WithPermissionSetArn(Aws::String&& value) { SetPermissionSetArn(std::move(value)); return *this;}

    /**
     * <p>The ARN of the permission set that is being provisioned. For more information
     * about ARNs, see <a href="/general/latest/gr/aws-arns-and-namespaces.html">Amazon
     * Resource Names (ARNs) and Amazon Web Services Service Namespaces</a> in the
     * <i>Amazon Web Services General Reference</i>.</p>
     */
    inline PermissionSetProvisioningStatus& WithPermissionSetArn(const char* value) { SetPermissionSetArn(value); return *this;}


    /**
     * <p>The message that contains an error or exception in case of an operation
     * failure.</p>
     */
    inline const Aws::String& GetFailureReason() const{ return m_failureReason; }

    /**
     * <p>The message that contains an error or exception in case of an operation
     * failure.</p>
     */
    inline bool FailureReasonHasBeenSet() const { return m_failureReasonHasBeenSet; }

    /**
     * <p>The message that contains an error or exception in case of an operation
     * failure.</p>
     */
    inline void SetFailureReason(const Aws::String& value) { m_failureReasonHasBeenSet = true; m_failureReason = value; }

    /**
     * <p>The message that contains an error or exception in case of an operation
     * failure.</p>
     */
    inline void SetFailureReason(Aws::String&& value) { m_failureReasonHasBeenSet = true; m_failureReason = std::move(value); }

    /**
     * <p>The message that contains an error or exception in case of an operation
     * failure.</p>
     */
    inline void SetFailureReason(const char* value) { m_failureReasonHasBeenSet = true; m_failureReason.assign(value); }

    /**
     * <p>The message that contains an error or exception in case of an operation
     * failure.</p>
     */
    inline PermissionSetProvisioningStatus& WithFailureReason(const Aws::String& value) { SetFailureReason(value); return *this;}

    /**
     * <p>The message that contains an error or exception in case of an operation
     * failure.</p>
     */
    inline PermissionSetProvisioningStatus& WithFailureReason(Aws::String&& value) { SetFailureReason(std::move(value)); return *this;}

    /**
     * <p>The message that contains an error or exception in case of an operation
     * failure.</p>
     */
    inline PermissionSetProvisioningStatus& WithFailureReason(const char* value) { SetFailureReason(value); return *this;}


    /**
     * <p>The date that the permission set was created.</p>
     */
    inline const Aws::Utils::DateTime& GetCreatedDate() const{ return m_createdDate; }

    /**
     * <p>The date that the permission set was created.</p>
     */
    inline bool CreatedDateHasBeenSet() const { return m_createdDateHasBeenSet; }

    /**
     * <p>The date that the permission set was created.</p>
     */
    inline void SetCreatedDate(const Aws::Utils::DateTime& value) { m_createdDateHasBeenSet = true; m_createdDate = value; }

    /**
     * <p>The date that the permission set was created.</p>
     */
    inline void SetCreatedDate(Aws::Utils::DateTime&& value) { m_createdDateHasBeenSet = true; m_createdDate = std::move(value); }

    /**
     * <p>The date that the permission set was created.</p>
     */
    inline PermissionSetProvisioningStatus& WithCreatedDate(const Aws::Utils::DateTime& value) { SetCreatedDate(value); return *this;}

    /**
     * <p>The date that the permission set was created.</p>
     */
    inline PermissionSetProvisioningStatus& WithCreatedDate(Aws::Utils::DateTime&& value) { SetCreatedDate(std::move(value)); return *this;}

  private:

    StatusValues m_status;
    bool m_statusHasBeenSet;

    Aws::String m_requestId;
    bool m_requestIdHasBeenSet;

    Aws::String m_accountId;
    bool m_accountIdHasBeenSet;

    Aws::String m_permissionSetArn;
    bool m_permissionSetArnHasBeenSet;

    Aws::String m_failureReason;
    bool m_failureReasonHasBeenSet;

    Aws::Utils::DateTime m_createdDate;
    bool m_createdDateHasBeenSet;
  };

} // namespace Model
} // namespace SSOAdmin
} // namespace Aws
