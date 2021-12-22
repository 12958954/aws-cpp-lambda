#include "DynamoDB.h"


JsonValue parse(Aws::Map<Aws::String, Aws::DynamoDB::Model::AttributeValue> item)
// item parser
{
  JsonValue re;
  for (const auto& i : item)
    {
      switch (i.second.GetType())
	{
	case Aws::DynamoDB::Model::ValueType::STRING:
	  {
	    re.WithString(i.first,i.second.GetS());
	    break;
	  }
	case Aws::DynamoDB::Model::ValueType::NUMBER:
	  {
	    re.WithString(i.first, i.second.GetN());
	    break;
	  }
	case Aws::DynamoDB::Model::ValueType::ATTRIBUTE_MAP:
	  {
	    re.WithString("ATTRIBUTE_MAP","ATTRIBUTE_MAP");
	    break;
	  }
	case Aws::DynamoDB::Model::ValueType::ATTRIBUTE_LIST:
	  {
	    re.WithObject(i.first,i.second.Jsonize());
	    break;
	  }
	default:
	  {
	    auto temp= i.second.GetM();
	    //re.WithObject(i.first, parse(temp));
	  }
	}
    }
  return re;
}

JsonValue DynamoGetItem(Aws::DynamoDB::DynamoDBClient const& dynamoClient, JsonView parameter)
{
  Aws::DynamoDB::Model::GetItemRequest req;
  req.SetTableName(parameter.GetString("table"));
  Aws::DynamoDB::Model::AttributeValue hashKey;
  hashKey.SetS(parameter.GetString("trackID"));
  req.AddKey("trackID", hashKey);
  // set up the request
  
  // if (!projection.empty()) req.SetProjectionExpression(projection);
  // Retrieve the item's fields and values
  const Aws::DynamoDB::Model::GetItemOutcome& result = dynamoClient.GetItem(req);
  // send the request to DynamoDB
  
  JsonValue re;
  if (result.IsSuccess())
    {
      // Reference the retrieved fields/values
      const Aws::Map<Aws::String, Aws::DynamoDB::Model::AttributeValue>& item = result.GetResult().GetItem();
      // get the item from the result
      
      if (item.size() > 0)
	{
	  re.WithObject("result",parse(item));
	  // parse the item
	}
      else
	{
	  re.WithString("message", "No item found with the key ");
	}
    }
  else
    {
      re.WithString("message", "Failed to get item: "+ result.GetError().GetMessage());
    }
  return re;
}
