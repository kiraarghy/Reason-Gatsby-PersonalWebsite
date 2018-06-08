import React from 'react'
import Link from 'gatsby-link'
import Body from '../../lib/js/src/components/body.bs.js'
import Footer from '../../lib/js/src/components/footer.bs.js'

const IndexPage = data => {
  console.log(data)
  return (
    <div style={{ backgroundColor: '#85DBC3' }}>
      <Body data={data.data} />
      <Footer data={data.data} />
    </div>
  )
}

export default IndexPage

export const query = graphql`
  query blah {
    contentfulAbout {
      name
      portrait {
        description
        file {
          url
        }
      }
      markdown {
        markdown
      }
      builtUsing {
        title
        file {
          url
        }
      }
    }
  }
`
