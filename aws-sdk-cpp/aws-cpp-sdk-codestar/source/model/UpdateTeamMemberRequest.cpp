/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/codestar/model/UpdateTeamMemberRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::CodeStar::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

UpdateTeamMemberRequest::UpdateTeamMemberRequest() : 
    m_projectIdHasBeenSet(false),
    m_userArnHasBeenSet(false),
    m_projectRoleHasBeenSet(false),
    m_remoteAccessAllowed(false),
    m_remoteAccessAllowedHasBeenSet(false)
{
}

Aws::String UpdateTeamMemberRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_projectIdHasBeenSet)
  {
   payload.WithString("projectId", m_projectId);

  }

  if(m_userArnHasBeenSet)
  {
   payload.WithString("userArn", m_userArn);

  }

  if(m_projectRoleHasBeenSet)
  {
   payload.WithString("projectRole", m_projectRole);

  }

  if(m_remoteAccessAllowedHasBeenSet)
  {
   payload.WithBool("remoteAccessAllowed", m_remoteAccessAllowed);

  }

  return payload.View().WriteReadable();
}

Aws::Http::HeaderValueCollection UpdateTeamMemberRequest::GetRequestSpecificHeaders() const
{
  Aws::Http::HeaderValueCollection headers;
  headers.insert(Aws::Http::HeaderValuePair("X-Amz-Target", "CodeStar_20170419.UpdateTeamMember"));
  return headers;

}




