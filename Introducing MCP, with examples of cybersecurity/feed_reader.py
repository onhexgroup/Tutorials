#Simple RSS feed reader MCP Server
#Codes related to the training "Introducing MCP, with examples of cybersecurity"
#https://youtu.be/FpD87EAw0Gk
#Https://onhexgroup.ir/mcp-ida-pro-shodan-burpsuite-mcp-server


from fastmcp import FastMCP
import feedparser

# Create MCP Server
mcp = FastMCP("FeedReader")


# Create Tool for get Title
@mcp.tool()
async def get_recent_posts(feed_url: str, count: int = 10) -> str:
    """Get the titles of the most recent posts from an RSS feed.
    
    Args:
        feed_url: The URL of the RSS feed.
        count: Number of posts to retrieve (default is 10).
    """
    feed = feedparser.parse(feed_url)
    if "entries" not in feed or not feed.entries:
        return "No posts found or invalid feed URL."
    
    titles = [entry.title for entry in feed.entries[:count]]
    return "\n".join(titles)

# run MCP server
if __name__ == "__main__":
    mcp.run()